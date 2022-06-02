#include "bmp.hpp"


BMP::~BMP() 
{
    for (int i = 0; i < m_bmpInfo.Height; i++)
        delete[] m_pixels[i];
    delete[] m_pixels;

}
void BMP::read() 
{
    std::ifstream in("in.bmp", std::ios::binary);

    in.read(reinterpret_cast<char*>(&m_bmpHeader), sizeof(BMPHEADER));
    in.read(reinterpret_cast<char*>(&m_bmpInfo), sizeof(BMPINFO));

    m_pixels = new Pixel * [m_bmpInfo.Height];
    for (int i = 0; i < m_bmpInfo.Height; i++)
        m_pixels[i] = new Pixel[m_bmpInfo.Width];

    for (int i = 0; i < m_bmpInfo.Height; i++) 
    {
        for (int j = 0; j < m_bmpInfo.Width; j++)
            in.read(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));

        if ((3 * m_bmpInfo.Width) % 4 != 0)
            for (int j = 0; j < 4 - (3 * m_bmpInfo.Width) % 4; j++) 
            {
                char c;
                in.read(&c, 1);
            }
    }

}
void BMP::write() 
{
    std::ofstream out("out.bmp", std::ios::binary);

    int width = m_bmpInfo.Width;
    int height = m_bmpInfo.Height;

    m_bmpHeader_new.Type = 0x4D42;
    m_bmpHeader_new.Size = 14 + 40 + (3 * width * height);
    if (width % 4 != 0)
        m_bmpHeader_new.Size += (4 - (3 * width) % 4) * height;
    m_bmpHeader_new.OffBits = 54;
    m_bmpHeader_new.Reserved1 = 0;
    m_bmpHeader_new.Reserved2 = 0;

    out.write(reinterpret_cast<char*>(&m_bmpHeader_new), sizeof(BMPHEADER));

    m_bmpInfo_new.BitCount = 24;
    m_bmpInfo_new.ClrImportant = 0;
    m_bmpInfo_new.ClrUsed = 0;
    m_bmpInfo_new.Compression = 0;
    m_bmpInfo_new.Height = height;
    m_bmpInfo_new.Planes = 1;
    m_bmpInfo_new.Size = 40;
    m_bmpInfo_new.SizeImage = m_bmpHeader_new.Size - 54;
    m_bmpInfo_new.Width = width;
    m_bmpInfo_new.XPelsPerMeter = 0;
    m_bmpInfo_new.YPelsPerMeter = 0;

    out.write(reinterpret_cast<char*>(&m_bmpInfo_new), sizeof(BMPINFO));

    for (int i = 0; i < m_bmpInfo_new.Height; i++) 
    {
        for (int j = 0; j < m_bmpInfo_new.Width; j++)
            out.write(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));

        if ((3 * m_bmpInfo_new.Width) % 4 != 0)
            for (int j = 0; j < 4 - (3 * m_bmpInfo_new.Width) % 4; j++) 
            {
                char c = 0;
                out.write(&c, 1);
            }
    }
}

void BMP::Filter()
{
    for (int i = 0; i < m_bmpInfo.Height; i++)
        for (int j = 0; j < m_bmpInfo.Width / 2; j++)
        {
            m_pixels[i][j].b -= 50;
            m_pixels[i][j].r -= 50;
            m_pixels[i][j].g -= 50;
        }
    for (int i = 0; i < m_bmpInfo.Height; i++)
        for (int j = 0; (m_bmpInfo.Width / 2)+1 < m_bmpInfo.Width; j++)
        {
            m_pixels[i][j].b += 50;
            m_pixels[i][j].r += 50;
            m_pixels[i][j].g += 50;
        }
}

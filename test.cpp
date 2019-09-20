#include <OpenImageIO/imageio.h>

int main()
{
    auto input = OIIO::ImageInput::open("file_path");

    auto const& image_spec = input->spec();
    auto read_format = image_spec.format;

    auto channel_count = (uint32_t)image_spec.nchannels;
    if (channel_count == 3)
        channel_count = 4;

    std::vector<unsigned char> pixels(1000);

    input->read_image(read_format, pixels.data(), 4);
    input->close();

    return 0;
}

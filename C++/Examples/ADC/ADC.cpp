#include <unistd.h>
#include <cstdio>
#include <Common/Util.h>
#include <Navio2/ADC_Navio2.h>
#include <vector>
#include <memory>

#define READ_FAILED -1



std::unique_ptr<ADC> get_converter()
{
  
        auto ptr = std::unique_ptr <ADC>{ new ADC_Navio2() };
        return ptr;
}

int main(int argc, char *argv[])
{
    if (check_apm()) {
        return 1;
    }
    auto adc = get_converter();
    adc->initialize();
    std::vector<float> results(adc->get_channel_count(),0.0);
    while (true)
    {
        for (int i = 0; i < adc->get_channel_count(); i++)
        {
            results[i] = adc->read(i);
            if (results[i] == READ_FAILED)
                return EXIT_FAILURE;
            printf("A%d: %.4fV ", i, results[i] / 1000);
        }
        printf("\n");

        usleep(500000);
    }


    return 0;
}

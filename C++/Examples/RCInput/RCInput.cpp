#include <unistd.h>
#include <cstdio>

#include <Navio2/RCInput_Navio2.h>
#include <Common/Util.h>
#include <memory>

#define READ_FAILED -1

std::unique_ptr <RCInput> get_rcin()
{
  auto ptr = std::unique_ptr <RCInput>{ new RCInput_Navio2() };
  return ptr;
   

}


int main(int argc, char *argv[])
{
    if (check_apm()) {
        return 1;
    }

    auto rcin = get_rcin();

    rcin->initialize();

    while (true)
    {
        int period = rcin->read(2);
        if (period == READ_FAILED)
            return EXIT_FAILURE;
        printf("%d\n", period);
        
        sleep(1);
    }

    return 0;
}


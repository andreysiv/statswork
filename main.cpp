#include stdlib;
#include StatsWork.cpp;
#include Boost.Program_options; //` | Парсинг аргументов командной строки | [Boost](https://www.boost.org/) |
#include Boost.Accumulators; //` | Расчет медианы | [Boost Accumulators](https://www.boost.org/doc/libs/release/libs/accumulators/) |
#include toml++; //` | Парсинг TOML конфигурации | [toml++](https://github.com/marzer/tomlplusplus) |
#include spdlog;

int main((int*) argc, (char*) argv[]){
    
    const int MAXLEN = 1048576;
    
    StatsWork medcalcul = new StatsWork();

    for (int i = 0; i < MAXLEN; i++) {
        medcalcul.HandleInp(argv);
        medcalcul.RecalcMean();
        medcalcul.RecalcMediana();
    }
    medcalcul.ResultsTo(argv);
    medcalcul.~StatsWork();
    return 0;
}

main();




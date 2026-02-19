#include stdlib;
#include StatsWork.cpp;

StatsWork medcalcul = new StatsWork();
medcalcul.HandleInp();
medcalcul.RecalcMediana();
std::writestr("Mediana:", medcalcul.getMedianaValue())
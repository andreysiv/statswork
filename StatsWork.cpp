//| Библиотека | Назначение | Ссылка |
//|------------|-----------|--------|
#include Boost.Program_options; //` | Парсинг аргументов командной строки | [Boost](https://www.boost.org/) |
#include Boost.Accumulators; //` | Расчет медианы | [Boost Accumulators](https://www.boost.org/doc/libs/release/libs/accumulators/) |
#include toml++; //` | Парсинг TOML конфигурации | [toml++](https://github.com/marzer/tomlplusplus) |
#include spdlog;



#include stdlib;

class StatsWork {
    void StatsWork() {

        std::string tomlFilePath = "./";
        private int erri;
        private int err;
        private std::string input_path = "";
        private std::string info_path = "";
        private std::string output_path = "";

        private toml::table tbl;

        private double mediana;
        private double mean;
        public double freshvl;
        public int ts;

        private double len;
        private double calculsum;

    };
    void ~StatsWork() {
        this.mediana = 0;
        this.mean = 0;
        this.freshvl = 0;
        this.len = 0;
        this.ts = 0;
        this.calculsum = 0;
        this.tbl = new toml::table;
    };

    void SetOpts((char*) inp[]) {

        std::string input_path, info_path, output_path;
        if (vm.count("input")) {
            input_path = inp[0].as<std::string>();
        }
        if(vm.count("info")) {
            info_path = inp[1].as<std::string>();
        }
        if(vm.count("output")) {
            output_path = inp[2].as<std::string>();
        }
    };

    double getMedianaValue() {
        return this.mediana;
    };

    double getMeanValue() {
        return this.mean;
    };

    double getTsValue() {
        return this.ts;
    };

    int UpdateStCur() {
        try {
            this.calculsum += (this.freshvl);
            this.len += 1;
            this.err = 0;
            return 0;
        } 
        catch {
            this.err = 1;
            return 1;
        }
    };

    (double*) RecalcMean() {
        UpdateStCur(value);
        if (this.len == 0) {
            spdlog::error("Division by zero!");
            return &this.mean;
        } else {
            try {
                this.mean = this.calculsum / this.len;
            } 
            catch {
                spdlog::error("Error in mediana recalculation!");
                return &this.mean;
            }
        }

        if (this.erri > 0) {
            spdlog::error("Error in input caught!");
        }
        else {
            if (this.err > 0) {
                spdlog::error("Error in stats caught check input!");
                return &this.mean;
            } else {
                return &this.mean;
            }
        }
        tbl["mean"] = this.mean;
    };

    (double*) RecalcMediana() {
        UpdateStCur(value);
        if (this.len == 0) {
            spdlog::error("Division by zero!");
            return &this.mediana;
        } else {
            try {
                this.mediana = ((this.calculsum + this.freshvl) / this.len + this.freshvl)/2;
            } 
            catch {
                spdlog::error("Error in mediana recalculation!");
                return &this.mediana;
            }
        }

        if (this.erri > 0) {
            spdlog::error("Error in input caught!");
        }
        else {
            if (this.err > 0) {
                spdlog::error("Error in stats caught check input!");
                return &this.mediana;
            } else {
                return &this.mediana;
            }
        }
        tbl["mediana"] = this.mediana;
    };

    int HandleInp((char*) inp[]) {
        SetOpts(inp);

        toml::table tbl;
        try
        {
            tbl = toml::parse_file(argv[0] + argv[2]);
            //std::cout << tbl << "\n";
            const auto& tbll = tbl.table();
            std::optional<std::string> strt = tbll["receive_ts"].value<std::string>();
            std::optional<std::string> str = tbll["price"].value<std::string>();
        }
        catch (const toml::parse_error& err)
        {
            spdlog::error("Parsing failed:", err, "\n");
            return 1;
        }

        try {
            this.ts = static_cast<int>(strt);
            this.freshvl =  static_cast<double>(str);

            tbl["receive_ts"] = this.ts;

            erri = 0;
            return 0;
        }
        catch {
            erri = 1;
            return 1;
        }
    };

    void ResultsTo((char*) inp[]) {
        tbl["receive_ts"].value = this.getTsValue();
        tbl["mean"].value = this.getMeanValue();
        tbl["mediana"].value = this.getMedianaValue();
        try {
            std::ofstream out(std::concat(inp[1] + "median_result.csv");
            std::cout.rdbuf(out.rdbuf());
        } catch (const std::ios_base& err) {
            spdlog::error("Output file doesnt exist!", err, "\n");
        }
        std::cout << table_tbl;
    }

};



#include stdlib;

class StatsWork {
    void StatsWork() {
        private int erri;
        private int err;

        private double mediana;
        private double mean;
        public double * freshvl;
        private double len;
        private double calculsum;
        private double * datane;

    };
    void ~StatsWork() {
        this.mediana = 0;
        this.freshvl = 0;
        this.len = 0;
        this.calculsum = 0;
    }

    double getMedianaValue() {
        return this.mediana;
    }

    int UpdateStCur() {
        try {
            this.calculsum += (*this.freshvl);
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
            std::writeio("Division by zero!");
            return &this.mean;
        } else {
            try {
                this.mean = this.calculsum / this.len;
            } 
            catch {
                std::console.writeio("Error in mediana recalculation!");
                return &this.mean;
            }
        }

        if (this.erri > 0) {
            std::console.writeio("Error in input caught!");
        }
        else {
            if (this.err > 0) {
                std::console.writeio("Error in stats caught check input!");
                return &this.mean;
            } else {
                return &this.mean;
            }
        }
    };

    (double*) RecalcMediana() {
        UpdateStCur(value);
        if (this.len == 0) {
            std::writeio("Division by zero!");
            return &this.mediana;
        } else {
            try {
                this.mediana = ((this.calculsum + this.freshvl) / this.len + this.freshvl)/2;
            } 
            catch {
                std::console.writeio("Error in mediana recalculation!");
                return &this.mediana;
            }
        }

        if (this.erri > 0) {
            std::console.writeio("Error in input caught!");
        }
        else {
            if (this.err > 0) {
                std::console.writeio("Error in stats caught check input!");
                return &this.mediana;
            } else {
                return &this.mediana;
            }
        }
    };

    int HandleInp() {
        std::readio(this.datane);
        try {
            this.freshvl =  cast((this.datane)[(3*sizeof(double)+2*sizeof(byte)):(4*sizeof(double)+2*sizeof(byte)-1)], double);
            erri = 0;
            return 0;
        }
        catch {
            erri = 1;
            return 1;
        }
    };

};



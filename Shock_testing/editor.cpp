#include "editor.hpp"

EDITOR::EDITOR(int dim, float aE)
{
    std::cout<<"Constructor called\n";
    std::cout<<"DIM_VALUES pointer: "<<DIM_VALUES<<"\n";
    DIMENSION = dim;
    DIM_VALUES = new float[DIMENSION];
    ALPHA_E = aE;
    activity = (float) rand() / RAND_MAX;
    std::cout<<"DIM_VALUES pointer: "<<DIM_VALUES<<"\n";

    // Calculating the power law distribution discrete pk-s
    // Every editor must know at least 1 discipline
    float p0 = 0;

    // DISCRETE PROBABILITIES FOR n INTEGER NUMBERS FROM 1-DIMENSION
    // k max = DIMENSION, ez alapján a normálási tényező
    float norm = 0;
    for (auto i = 1; i <= DIMENSION; ++i)
        norm += (float)pow(i, -ALPHA_E);
    
    std::vector<float> pks;
    for (auto k = 1; k <= DIMENSION; ++k)
    {
        float pk = (float)pow(k, -ALPHA_E) / norm;
        pks.push_back(pk);
    }

    // determine how many disciplines does each editor know
    float f = (float)rand() / RAND_MAX;
    float base = 0;
    int m = 1; // number of disciplines known by each editor
    for (auto i = 0; i < DIMENSION; ++i)
    {
        if (base <= f && f <= base + pks.at(i))
        {
            m = i + 1;
            base += pks.at(i);
        }
        else
        {
            base += pks[i];
        }
    }

    // select m random disciplines from the DIMENSION disciplines
    std::vector<int> chosen_ones;
    while (chosen_ones.size() != m)
    {
        int pot_new = rand() % DIMENSION;
        bool is_ok = true;
        for (auto i = 0; i < chosen_ones.size(); ++i)
        {
            if (chosen_ones.at(i) == pot_new)
                is_ok = false;
        }
        if (is_ok)
            chosen_ones.push_back(pot_new);
    }

    std::sort(chosen_ones.begin(), chosen_ones.end());

    // fill up the random disciplines
    int j = 0;
    for (auto i = 0; i < DIMENSION; ++i)
    {
        if (i == chosen_ones[j])
        {
            this->DIM_VALUES[i] = (float)rand() / RAND_MAX;
            if (j < m)
                j += 1;
        }

        else
            DIM_VALUES[i] = 0;
    }

    // Hopefully finished;
    chosen_ones.clear();
    chosen_ones.shrink_to_fit();

    pks.clear();
    pks.shrink_to_fit();
}

EDITOR::EDITOR(const EDITOR &e1){
    DIMENSION = e1.DIMENSION;
    DIM_VALUES = new float[DIMENSION];
    ALPHA_E = e1.ALPHA_E;
    activity = e1.activity;
    for(auto i = 0; i < DIMENSION; ++i){
        DIM_VALUES[i] = e1.DIM_VALUES[i];
    }
}

void EDITOR::ChangeParams_Editors(int new_dim, float new_aE){
    DIMENSION = new_dim;
    delete[] DIM_VALUES;
    DIM_VALUES = new float[DIMENSION];
    ALPHA_E = new_aE;

    // Calculating the power law distribution discrete pk-s
    // Every editor must know at least 1 discipline
    float p0 = 0;

    // DISCRETE PROBABILITIES FOR n INTEGER NUMBERS FROM 1-DIMENSION
    // k max = DIMENSION, ez alapján a normálási tényező
    float norm = 0;
    for (auto i = 1; i <= DIMENSION; ++i)
        norm += (float)pow(i, -ALPHA_E);
    
    std::vector<float> pks;
    for (auto k = 1; k <= DIMENSION; ++k)
    {
        float pk = (float)pow(k, -ALPHA_E) / norm;
        pks.push_back(pk);
    }

    // determine how many disciplines does each editor know
    float f = (float)rand() / RAND_MAX;
    float base = 0;
    int m = 1; // number of disciplines known by each editor
    for (auto i = 0; i < DIMENSION; ++i)
    {
        if (base <= f && f <= base + pks.at(i))
        {
            m = i + 1;
            base += pks.at(i);
        }
        else
        {
            base += pks[i];
        }
    }

    // select m random disciplines from the DIMENSION disciplines
    std::vector<int> valasztottak;
    while (valasztottak.size() != m)
    {
        int pot_new = rand() % DIMENSION;
        bool mehet = true;
        for (auto i = 0; i < valasztottak.size(); ++i)
        {
            if (valasztottak.at(i) == pot_new)
                mehet = false;
        }
        if (mehet)
            valasztottak.push_back(pot_new);
    }

    std::sort(valasztottak.begin(), valasztottak.end());

    // fill up the random disciplines
    int j = 0;
    for (auto i = 0; i < DIMENSION; ++i)
    {
        if (i == valasztottak[j])
        {
            this->DIM_VALUES[i] = (float)rand() / RAND_MAX;
            if (j < m)
                j += 1;
        }

        else
            DIM_VALUES[i] = 0;
    }

    // Hopefully finished;
    valasztottak.clear();
    valasztottak.shrink_to_fit();

    pks.clear();
    pks.shrink_to_fit();
}

EDITOR::~EDITOR(){
    delete[] DIM_VALUES;
}

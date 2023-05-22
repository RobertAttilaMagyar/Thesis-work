#include "article.hpp"
#include <cmath>

ARTICLE::ARTICLE(int dim, float aA)
{
    DIMENSION = dim;
    DIM_VALUES = new float[DIMENSION];
    ALPHA_A = aA;
    

    // Calculating the power law distribution discrete pk-s
    // Every editor must know at least 1 discipline
    float p0 = 0;

    // DISCRETE PROBABILITIES FOR n INTEGER NUMBERS FROM 1-DIMENSION
    // k max = DIMENSION, ez alapján a normálási tényező
    float norm = 0;
    for (auto i = 1; i <= DIMENSION; ++i)
        norm += (float)pow(i, -ALPHA_A);

    std::vector<float> pks;
    for (auto k = 1; k <= DIMENSION; ++k)
    {
        float pk = (float)pow(k, -ALPHA_A) / norm;
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
            this->DIM_VALUES[i] = 0;
            if (j < m)
                j += 1;
        }

        else
            DIM_VALUES[i] = 1;
    }

    // Hopefully finished;
    valasztottak.clear();
    valasztottak.shrink_to_fit();

    pks.clear();
    pks.shrink_to_fit();
}

void ARTICLE::ChangeParam_Articles(int new_dim, float new_aA)
{
    DIMENSION = new_dim;
    delete[] DIM_VALUES;
    DIM_VALUES = new float[DIMENSION];
    ALPHA_A = new_aA;

    // Calculating the power law distribution discrete pk-s
    // Every editor must know at least 1 discipline
    float p0 = 0;

    // DISCRETE PROBABILITIES FOR n INTEGER NUMBERS FROM 1-DIMENSION
    // k max = DIMENSION, ez alapján a normálási tényező
    float norm = 0;
    for (auto i = 1; i <= DIMENSION; ++i)
        norm += (float)pow(i, -ALPHA_A);

    std::vector<float> pks;
    for (auto k = 1; k <= DIMENSION; ++k)
    {
        float pk = (float)pow(k, -ALPHA_A) / norm;
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
            this->DIM_VALUES[i] = 0;
            if (j < m)
                j += 1;
        }

        else
            DIM_VALUES[i] = 1;
    }

    // Hopefully finished;
    valasztottak.clear();
    valasztottak.shrink_to_fit();

    pks.clear();
    pks.shrink_to_fit();

}
#ifndef STATICCALCULATION_COEFFICIENT_SERVICE_H
#define STATICCALCULATION_COEFFICIENT_SERVICE_H

#include "Application/Backend/coefficient_parser.h"

namespace Backend
{

class CoefficientService
{
  public:
    CoefficientService();
    ~CoefficientService();

    std::map<std::string, float> QueryByKey(const std::string& key);
    Coefficients* GetCoefficientsDatabase();

  private:
    Coefficients* coefficients_database_;
};

}
#endif  // STATICCALCULATION_COEFFICIENT_SERVICE_H

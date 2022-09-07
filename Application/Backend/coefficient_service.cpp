#include "coefficient_service.h"

namespace Backend
{

CoefficientService::CoefficientService() : coefficients_database_(new Coefficients())
{
    coefficients_database_ = CoefficientParser::Load();
}

CoefficientService::~CoefficientService()
{
    if (coefficients_database_ != nullptr)
    {
        delete coefficients_database_;
        coefficients_database_ = nullptr;
    }
}

std::map<std::string, float> CoefficientService::QueryByKey(const std::string& key)
{
    assert(!coefficients_database_->empty());

    std::map<std::string, float> queried_values;

    for (const auto& element : coefficients_database_->at(key))
    {
        queried_values.emplace(element);
    }

    return queried_values;
}

Coefficients* CoefficientService::GetCoefficientsDatabase()
{
    return coefficients_database_;
}

}  // namespace Backend

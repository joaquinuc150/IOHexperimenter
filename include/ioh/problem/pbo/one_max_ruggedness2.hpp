#pragma once
#include "ioh/problem/utils.hpp"
#include "pbo_problem.hpp"

namespace ioh
{
    namespace problem
    {
        namespace pbo
        {
            class OneMaxRuggedness2 final: public PBOProblem<OneMaxRuggedness2>
            {
            protected:
                std::vector<double> evaluate(const std::vector<int> &x) override
                {
                    auto result = 0.0;
                    for (auto i = 0; i != meta_data_.n_variables; ++i)
                        result += x[i];
                    return {utils::ruggedness2(result, meta_data_.n_variables)};
                }

            public:
                /**
                 * \brief Construct a new OneMax_Ruggedness2 object. Definition refers to
                 *https://doi.org/10.1016/j.asoc.2019.106027
                 *
                 * \param instance The instance number of a problem, which controls the transformation
                 * performed on the original problem.
                 * \param n_variables The dimensionality of the problem to created, 4 by default.
                 **/
                OneMaxRuggedness2(const int instance, const int n_variables) :
                    PBOProblem(9, instance, n_variables, "OneMaxRuggedness2")
                {
                    objective_.x = std::vector<int>(n_variables,1);
                    objective_.y = evaluate(objective_.x);
                }
            };
        } // namespace pbo
    } // namespace problem
} // namespace ioh
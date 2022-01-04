/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:24 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/04 18:08:26 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_RESOLVER
#define DEF_RESOLVER

#include <string>
#include <vector>

class Solver
{
    public:

    Solver(std::vector<double> coeff);
    double squareRoot(double X);
    void showCoeff();
    void solveEquation();
    void solveNoDegree();
    void solveImpossible();
    void solveOneDegree();
    void solveTwoDegree();
    void solveCaseUp(double delta);
    void solveCaseEqual();
    void solveCaseDown(double delta);

    private:

    std::vector<double> m_temp;
    std::vector<double> m_coeff;
};

#endif
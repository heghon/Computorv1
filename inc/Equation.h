/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:33 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/04 14:53:27 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_EQUATION
#define DEF_EQUATION

#include <string>
#include <vector>

class Equation
{
    public:

    Equation(std::string totalEquation, std::vector<std::string> leftOpe, std::vector<std::string> rightOpe);
    void showTheEquation();
    std::vector<double> getFinalCoeff();
    void handleCoeff();
    void putCoeff(std::vector<std::string> opeTab, int side);
    void showReducedForm();
    void showPolynomialDegree();

    private:

    std::vector<std::string> m_leftOpe;
    std::vector<std::string> m_rightOpe;
    std::vector<double> m_temp;
    std::vector<double> m_finalCoeff;
    std::string m_totalEquation;
};

#endif
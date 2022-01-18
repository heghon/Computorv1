/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EquationSimplified.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:14:31 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/18 16:40:02 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_EQUATIONSIMPLIFIED
#define DEF_EQUATIONSIMPLIFIED

#include <string>
#include <vector>

class Equationsimplified
{
    public:

    Equationsimplified(std::string totalEquation, std::vector<std::string> leftOpe, std::vector<std::string> rightOpe);
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
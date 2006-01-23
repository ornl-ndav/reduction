/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 * 
 * For this software and its associated documentation, permission is granted 
 * to reproduce, prepare derivative works, and distribute copies to the public 
 * for any purpose and without fee.
 *  
 * This material was prepared as an account of work sponsored by an agency of 
 * the United States Government.  Neither the United States Government nor the 
 * United States Department of Energy, nor any of their employees, makes any 
 * warranty, express or implied, or assumes any legal liability or 
 * responsibility for the accuracy, completeness, or usefulness of any 
 * information, apparatus, product, or process disclosed, or represents that 
 * its use would not infringe privately owned rights.
 *
 */

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  // SNS-FIXME

  int num_val = 20;

  //float
  Nessi::Vector<float> f_initial_energy;
  Nessi::Vector<float> f_initial_energy_err2;
  Nessi::Vector<float> f_final_energy;
  Nessi::Vector<float> f_final_energy_err2;
  Nessi::Vector<float> f_energy_transfer(num_val);
  Nessi::Vector<float> f_energy_transfer_err2(num_val);
  Nessi::Vector<float> f_true_energy_transfer(num_val);
  Nessi::Vector<float> f_true_energy_transfer_err2(num_val);
  float f_h2;

  //double
  Nessi::Vector<double> d_initial_energy;
  Nessi::Vector<double> d_initial_energy_err2;
  Nessi::Vector<double> d_final_energy;
  Nessi::Vector<double> d_final_energy_err2;
  Nessi::Vector<double> d_energy_transfer(num_val);
  Nessi::Vector<double> d_energy_transfer_err2(num_val);
  Nessi::Vector<double> d_true_energy_transfer(num_val);
  Nessi::Vector<double> d_true_energy_transfer_err2(num_val);
  double d_h2;


  int error_case_1 = 0;
  int error_case_2 = 0;
  int error_case_3 = 0;
  int error_case_4 = 0;

  int error = 0;

  f_h2 = static_cast<float>(PhysConst::H) * static_cast<float>(PhysConst::H);
  d_h2 = static_cast<double>(PhysConst::H) * static_cast<double>(PhysConst::H);

  // ****case 1****

  f_initial_energy.push_back(static_cast<float>(26.3454));
  f_initial_energy_err2.push_back(static_cast<float>(24.34395));
  d_initial_energy.push_back(static_cast<double>(26.3454));
  d_initial_energy_err2.push_back(static_cast<double>(24.34395));

  for(int i = 0 ; i < num_val ; i++)
    {
      f_final_energy.push_back(static_cast<float>(i+1));
      f_final_energy_err2.push_back(static_cast<float>(i+2));

      d_final_energy.push_back(static_cast<double>(i+1));
      d_final_energy_err2.push_back(static_cast<double>(i+2));
    }

  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
                             f_final_energy, f_final_energy_err2,
                             f_energy_transfer, f_energy_transfer_err2);

  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
                             d_final_energy, d_final_energy_err2,
                             d_energy_transfer, d_energy_transfer_err2);

  for(int i = 0 ; i < num_val ; i++)
    {
      f_true_energy_transfer[i] = (f_initial_energy[0] - f_final_energy[i]) /
        static_cast<float>(PhysConst::H);
      f_true_energy_transfer_err2[i] = (f_initial_energy_err2[0] +
                                        f_final_energy_err2[i]) / f_h2;

      d_true_energy_transfer[i] = (d_initial_energy[0] - d_final_energy[i]) /
        static_cast<double>(PhysConst::H);
      d_true_energy_transfer_err2[i] = (d_initial_energy_err2[0] +
                                        d_final_energy_err2[i]) / d_h2;
    }

  //compare results for case 1

  while(1)
    {
      Utils::vector_comparison(f_energy_transfer, f_true_energy_transfer,
                               error_case_1, 10);
      if (error_case_1 != 0) break;
      Utils::vector_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2,
                               error_case_1, 20);
      if (error_case_1 != 0) break;

      Utils::vector_comparison(d_energy_transfer, d_true_energy_transfer,
                               error_case_1, 110);
      if (error_case_1 != 0) break;
      Utils::vector_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2,
                               error_case_1, 120);
      if (error_case_1 != 0) break;

      break;
    }

  // ****case 2****

  f_final_energy.clear();
  f_final_energy_err2.clear();
  f_initial_energy_err2.clear();
  f_initial_energy.clear();

  d_final_energy.clear();
  d_final_energy_err2.clear();
  d_initial_energy_err2.clear();
  d_initial_energy.clear();


  f_final_energy.push_back(static_cast<float>(1.34566));
  f_final_energy_err2.push_back(static_cast<float>(2.445456));

  d_final_energy.push_back(static_cast<double>(1.34566));
  d_final_energy_err2.push_back(static_cast<double>(2.445456));

   for(int i = 0 ; i < num_val ; i++)
    {
      f_initial_energy.push_back(3.*static_cast<float>(i+2));
      f_initial_energy_err2.push_back(static_cast<float>(i+3));

      d_initial_energy.push_back(3.*static_cast<double>(i+2));
      d_initial_energy_err2.push_back(static_cast<double>(i+3));
    }

  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
                             f_final_energy, f_final_energy_err2,
                             f_energy_transfer, f_energy_transfer_err2);

  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
                             d_final_energy, d_final_energy_err2,
                             d_energy_transfer, d_energy_transfer_err2);

  for(int i = 0 ; i < num_val ; i++)
    {
      f_true_energy_transfer[i] = (f_initial_energy[i] - f_final_energy[0]) /
        static_cast<float>(PhysConst::H);
      f_true_energy_transfer_err2[i] = (f_initial_energy_err2[i] +
                                        f_final_energy_err2[0]) / f_h2;

      d_true_energy_transfer[i] = (d_initial_energy[i] - d_final_energy[0]) /
        static_cast<double>(PhysConst::H);
      d_true_energy_transfer_err2[i] = (d_initial_energy_err2[i] +
                                        d_final_energy_err2[0]) / d_h2;
    }

  //compare results for case 2
  while(1)
    {
      Utils::vector_comparison(f_energy_transfer, f_true_energy_transfer,
                               error_case_2, 10);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2,
                               error_case_2, 20);
      if (error_case_2 != 0) break;

      Utils::vector_comparison(d_energy_transfer, d_true_energy_transfer,
                               error_case_2, 110);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2,
                               error_case_2, 120);
      if (error_case_2 != 0) break;

      break;
    }


  // ****case 3****

  f_final_energy.clear();
  f_final_energy_err2.clear();
  f_initial_energy_err2.clear();
  f_initial_energy.clear();

  d_final_energy.clear();
  d_final_energy_err2.clear();
  d_initial_energy_err2.clear();
  d_initial_energy.clear();

  f_final_energy.push_back(static_cast<float>(1.34566));
  f_final_energy_err2.push_back(static_cast<float>(1.445456));
  f_initial_energy.push_back(static_cast<float>(43.34546));
  f_initial_energy_err2.push_back(static_cast<float>(5.00909));

  d_final_energy.push_back(static_cast<double>(1.34566));
  d_final_energy_err2.push_back(static_cast<double>(1.445456));
  d_initial_energy.push_back(static_cast<double>(43.34546));
  d_initial_energy_err2.push_back(static_cast<double>(5.00909));

  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
                             f_final_energy, f_final_energy_err2,
                             f_energy_transfer, f_energy_transfer_err2);

  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
                             d_final_energy, d_final_energy_err2,
                             d_energy_transfer, d_energy_transfer_err2);

  f_true_energy_transfer[0] = (f_initial_energy[0] - f_final_energy[0]) /
    static_cast<float>(PhysConst::H);
  f_true_energy_transfer_err2[0] = (f_initial_energy_err2[0] +
                                    f_final_energy_err2[0]) / f_h2;

  d_true_energy_transfer[0] = (d_initial_energy[0] - d_final_energy[0]) /
    static_cast<double>(PhysConst::H);
  d_true_energy_transfer_err2[0] = (d_initial_energy_err2[0] +
                                    d_final_energy_err2[0]) / d_h2;

  //compare results for case 3
    while(1)
    {
      Utils::vector_comparison(f_energy_transfer, f_true_energy_transfer,
                               error_case_3, 10);
      if (error_case_3 != 0) break;
      Utils::vector_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2,
                               error_case_3, 20);
      if (error_case_3 != 0) break;

      Utils::vector_comparison(d_energy_transfer, d_true_energy_transfer,
                               error_case_3, 110);
      if (error_case_3 != 0) break;
      Utils::vector_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2,
                               error_case_3, 120);
      if (error_case_3 != 0) break;

      break;
    }


  // ****case 4****

  f_final_energy.clear();
  f_final_energy_err2.clear();
  f_initial_energy_err2.clear();
  f_initial_energy.clear();

  d_final_energy.clear();
  d_final_energy_err2.clear();
  d_initial_energy_err2.clear();
  d_initial_energy.clear();

  for(int i = 0 ; i < num_val ; i++)
    {
      f_initial_energy.push_back(3.*static_cast<float>(i+3));
      f_initial_energy_err2.push_back(static_cast<float>(i+5));
      f_final_energy.push_back(3.*static_cast<float>(i+2));
      f_final_energy.push_back(static_cast<float>(i+2));

      d_initial_energy.push_back(3.*static_cast<double>(i+3));
      d_initial_energy_err2.push_back(static_cast<double>(i+5));
      d_final_energy.push_back(3.*static_cast<double>(i+2));
      d_final_energy.push_back(static_cast<double>(i+2));
    }

  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
                             f_final_energy, f_final_energy_err2,
                             f_energy_transfer, f_energy_transfer_err2);

  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
                             d_final_energy, d_final_energy_err2,
                             d_energy_transfer, d_energy_transfer_err2);

  for(int i = 0 ; i < num_val ; i++)
    {
      f_true_energy_transfer[i] = (f_initial_energy[i] - f_final_energy[i]) /
        static_cast<float>(PhysConst::H);
      f_true_energy_transfer_err2[i] = (f_initial_energy_err2[i] +
                                        f_final_energy_err2[i]) / f_h2;

      d_true_energy_transfer[i] = (d_initial_energy[i] - d_final_energy[i]) /
        static_cast<double>(PhysConst::H);
      d_true_energy_transfer_err2[i] = (d_initial_energy_err2[i] +
                                        d_final_energy_err2[i]) / d_h2;
    }

    while(1)
    {
      Utils::vector_comparison(f_energy_transfer, f_true_energy_transfer,
                               error_case_4, 10);
      if (error_case_4 != 0) break;
      Utils::vector_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2,
                               error_case_4, 20);
      if (error_case_4 != 0) break;

      Utils::vector_comparison(d_energy_transfer, d_true_energy_transfer,
                               error_case_4, 110);
      if (error_case_4 != 0) break;
      Utils::vector_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2,
                               error_case_4, 120);
      if (error_case_4 != 0) break;

      break;
    }

    error = error_case_1 + error_case_2 + error_case_3 + error_case_4;

    cout << "energy_transfer_test.cpp..........";

    switch (error)
      {
      case 0:
        cout << "Functionality OK" << endl;
        break;
      default:
        {
          if (error_case_1 != 0)
            {
              cout << "(sz1 == 1 && sz2 != 1):" << endl;
              switch (error_case_1)
                {
                case 10:
                  cout << "(float) FAILED....Output vector different from "
                       << "vector expected" << endl;
                  break;
                case 20:
                  cout << "(float) FAILED....Output error vector different "
                       <<"from vector expected" << endl;
                  break;
                case 110:
                  cout << "(double) FAILED....Output vector different from "
                       << "vector expected" << endl;
                  break;
                case 120:
                  cout << "(double) FAILED....Output error vector different "
                       << "from vector expected" << endl;
                  break;
                }
            }
          else if (error_case_2 != 0)
            {
              cout << "(sz1 != 1 && sz2 == 1):" << endl;
              switch (error_case_2)
                {
                case 10:
                  cout << "(float) FAILED....Output vector different from "
                       << "vector expected" << endl;
                  break;
                case 20:
                  cout << "(float) FAILED....Output error vector different "
                       << "from vector expected" << endl;
                  break;
                case 110:
                  cout << "(double) FAILED....Output vector different from "
                       << "vector expected" << endl;
                  break;
                case 120:
                  cout << "(double) FAILED....Output error vector different "
                       << "from vector expected" << endl;
                  break;
                }
            }
          else if (error_case_3 != 0)
            {
              cout << "(sz1 == 1 && sz2 == 1):" << endl;
              switch (error_case_3)
                {
                case 10:
                  cout << "(float) FAILED....Output vector different from vector"
                       << " expected" << endl;
                  break;
                case 20:
                  cout << "(float) FAILED....Output error vector different from "
                       << "vector expected" << endl;
                  break;
                case 110:
                  cout << "(double) FAILED....Output vector different from "
                       << "vector expected" << endl;
                  break;
                case 120:
                  cout << "(double) FAILED....Output error vector different from"
                       << " vector expected" << endl;
                  break;
                }
            }
          else if (error_case_4 != 0)
            {
              cout << "(sz1 != 1 && sz2 != 1):" << endl;
              switch (error_case_4)
                {
                case 10:
                  cout << "(float) FAILED....Output vector different from vector"
                       << " expected" << endl;
                  break;
                case 20:
                  cout << "(float) FAILED....Output error vector different from "
                       << "vector expected" << endl;
                  break;
                case 110:
                  cout << "(double) FAILED....Output vector different from "
                       << "vector expected" << endl;
                  break;
                case 120:
                  cout << "(double) FAILED....Output error vector different from"
                       << " vector expected" << endl;
                  break;
                }
            }
        }
      }
    return 0;
}

// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2008 Bauhaus University Weimar                                                   */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  matrix.cpp                                                                      */
/*  project    :  lectures in programming && software engineering, winter 08/09                   */
/*  description:  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "matrix.hpp"

// includes, system

#include <algorithm>              // std::copy, std::swap_ranges
#include <cmath>                  // std::cos, std::sin
#include <iomanip>                // std::fixed, std::setprecision
#include <ostream>                // std::ostream
#include <limits>                 // std::numeric_limits

// includes, project
#include <point.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  double const null_array16[16] = {
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0
  };

  double const ident_array16[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0
  };
  
  // functions, internal

  double
  det3_helper(double a1, double a2, double a3,
              double b1, double b2, double b3,
              double c1, double c2, double c3)
  {
    return ((a1 * b2 * c3) + (a2 * b3 * c1) + (a3 * b1 * c2) -
            (a1 * b3 * c2) - (a2 * b1 * c3) - (a3 * b2 * c1));
  }
  
} // namespace {

namespace math3d {
  
  // variables, exported
  
  // functions, exported
  
  matrix::matrix()
  {
    std::copy(ident_array16, ident_array16+16, data_);
  }
  
  matrix::matrix(matrix const& rhs)
  {
    std::copy(rhs.data_, rhs.data_+16, data_);
  }

  matrix::matrix(double const a[16])
  {
    std::copy(a, a+16, data_);
  }

  matrix::~matrix()
  {}

  void
  matrix::swap(matrix& rhs)
  {
    std::swap_ranges(data_, data_+16, rhs.data_);
  }

  matrix&
  matrix::operator=(matrix const& rhs)
  {
    matrix tmp(rhs);

    swap(tmp);
    
    return *this;
  }

  double const&
  matrix::operator()(matrix::cols a, matrix::rows b) const
  {
    return data_[(b * 4) + a];
  }

  double&
  matrix::operator()(matrix::cols a, matrix::rows b)
  {
    return data_[(b * 4) + a];
  }

  double const&
  matrix::operator[](matrix::component idx) const
  {
    return data_[idx];
  }

  double&
  matrix::operator[](matrix::component idx)
  {
    return data_[idx];
  }

  matrix&
  matrix::operator*=(matrix const& rhs)
  {
    matrix tmp;
    
    tmp.data_[ 0] = (data_[ 0] * rhs.data_[ 0] +
                     data_[ 4] * rhs.data_[ 1] +
                     data_[ 8] * rhs.data_[ 2] +
                     data_[12] * rhs.data_[ 3]);
    tmp.data_[ 1] = (data_[ 1] * rhs.data_[ 0] +
                     data_[ 5] * rhs.data_[ 1] +
                     data_[ 9] * rhs.data_[ 2] +
                     data_[13] * rhs.data_[ 3]);
    tmp.data_[ 2] = (data_[ 2] * rhs.data_[ 0] +
                     data_[ 6] * rhs.data_[ 1] +
                     data_[10] * rhs.data_[ 2] +
                     data_[14] * rhs.data_[ 3]);
    tmp.data_[ 3] = (data_[ 3] * rhs.data_[ 0] +
                     data_[ 7] * rhs.data_[ 1] +
                     data_[11] * rhs.data_[ 2] +
                     data_[15] * rhs.data_[ 3]);
    tmp.data_[ 4] = (data_[ 0] * rhs.data_[ 4] +
                     data_[ 4] * rhs.data_[ 5] +
                     data_[ 8] * rhs.data_[ 6] +
                     data_[12] * rhs.data_[ 7]);
    tmp.data_[ 5] = (data_[ 1] * rhs.data_[ 4] +
                     data_[ 5] * rhs.data_[ 5] +
                     data_[ 9] * rhs.data_[ 6] +
                     data_[13] * rhs.data_[ 7]);
    tmp.data_[ 6] = (data_[ 2] * rhs.data_[ 4] +
                     data_[ 6] * rhs.data_[ 5] +
                     data_[10] * rhs.data_[ 6] +
                     data_[14] * rhs.data_[ 7]);
    tmp.data_[ 7] = (data_[ 3] * rhs.data_[ 4] +
                     data_[ 7] * rhs.data_[ 5] +
                     data_[11] * rhs.data_[ 6] +
                     data_[15] * rhs.data_[ 7]);
    tmp.data_[ 8] = (data_[ 0] * rhs.data_[ 8] +
                     data_[ 4] * rhs.data_[ 9] +
                     data_[ 8] * rhs.data_[10] +
                     data_[12] * rhs.data_[11]);
    tmp.data_[ 9] = (data_[ 1] * rhs.data_[ 8] +
                     data_[ 5] * rhs.data_[ 9] +
                     data_[ 9] * rhs.data_[10] +
                     data_[13] * rhs.data_[11]);
    tmp.data_[10] = (data_[ 2] * rhs.data_[ 8] +
                     data_[ 6] * rhs.data_[ 9] +
                     data_[10] * rhs.data_[10] +
                     data_[14] * rhs.data_[11]);
    tmp.data_[11] = (data_[ 3] * rhs.data_[ 8] +
                     data_[ 7] * rhs.data_[ 9] +
                     data_[11] * rhs.data_[10] +
                     data_[15] * rhs.data_[11]);
    tmp.data_[12] = (data_[ 0] * rhs.data_[12] +
                     data_[ 4] * rhs.data_[13] +
                     data_[ 8] * rhs.data_[14] +
                     data_[12] * rhs.data_[15]);
    tmp.data_[13] = (data_[ 1] * rhs.data_[12] +
                     data_[ 5] * rhs.data_[13] +
                     data_[ 9] * rhs.data_[14] +
                     data_[13] * rhs.data_[15]);
    tmp.data_[14] = (data_[ 2] * rhs.data_[12] +
                     data_[ 6] * rhs.data_[13] +
                     data_[10] * rhs.data_[14] +
                     data_[14] * rhs.data_[15]);
    tmp.data_[15] = (data_[ 3] * rhs.data_[12] +
                     data_[ 7] * rhs.data_[13] +
                     data_[11] * rhs.data_[14] +
                     data_[15] * rhs.data_[15]);
    
    swap(tmp);
    
    return *this;
  }

  matrix&
  matrix::operator*=(double rhs)
  {
    for (unsigned idx = 0; idx < 16; ++idx)
      data_[idx] *= rhs;
    
    return *this;
  }

  matrix&
  matrix::operator/=(double rhs)
  {
    for (unsigned idx = 0; idx < 16; ++idx)
      data_[idx] /= rhs;
    
    return *this;
  }
  
  double
  matrix::determinant() const
  {
    double const& a1(data_[ 0]);
    double const& b1(data_[ 4]);
    double const& c1(data_[ 8]);
    double const& d1(data_[12]);
    
    double const& a2(data_[ 1]);
    double const& b2(data_[ 5]);
    double const& c2(data_[ 9]);
    double const& d2(data_[13]);
    
    double const& a3(data_[ 2]);
    double const& b3(data_[ 6]);
    double const& c3(data_[10]);
    double const& d3(data_[14]);
    
    double const& a4(data_[ 3]);
    double const& b4(data_[ 7]);
    double const& c4(data_[11]);
    double const& d4(data_[15]);
    
    return (a1 * det3_helper(b2, b3, b4, c2, c3, c4, d2, d3, d4) -
            b1 * det3_helper(a2, a3, a4, c2, c3, c4, d2, d3, d4) +
            c1 * det3_helper(a2, a3, a4, b2, b3, b4, d2, d3, d4) -
            d1 * det3_helper(a2, a3, a4, b2, b3, b4, c2, c3, c4));
  }

  double
  matrix::trace() const
  {
    return data_[0] + data_[5] + data_[10] + data_[15];
  }
  
  bool
  matrix::invert()
  {
    bool         result(false);
    double const d(determinant());
    
    if (0.0 != d) {
      double const& a1(data_[ 0]);
      double const& b1(data_[ 4]);
      double const& c1(data_[ 8]);
      double const& d1(data_[12]);
      double const& a2(data_[ 1]);
      double const& b2(data_[ 5]);
      double const& c2(data_[ 9]);
      double const& d2(data_[13]);
      double const& a3(data_[ 2]);
      double const& b3(data_[ 6]);
      double const& c3(data_[10]);
      double const& d3(data_[14]);
      double const& a4(data_[ 3]);
      double const& b4(data_[ 7]);
      double const& c4(data_[11]);
      double const& d4(data_[15]);
      
      double const di(1.0 / d);
      
      matrix tmp;

      tmp.data_[ 0] =  det3_helper(b2, b3, b4, c2, c3, c4, d2, d3, d4) * di;
      tmp.data_[ 1] = -det3_helper(a2, a3, a4, c2, c3, c4, d2, d3, d4) * di;
      tmp.data_[ 2] =  det3_helper(a2, a3, a4, b2, b3, b4, d2, d3, d4) * di;
      tmp.data_[ 3] = -det3_helper(a2, a3, a4, b2, b3, b4, c2, c3, c4) * di;
      tmp.data_[ 4] = -det3_helper(b1, b3, b4, c1, c3, c4, d1, d3, d4) * di;
      tmp.data_[ 5] =  det3_helper(a1, a3, a4, c1, c3, c4, d1, d3, d4) * di;
      tmp.data_[ 6] = -det3_helper(a1, a3, a4, b1, b3, b4, d1, d3, d4) * di;
      tmp.data_[ 7] =  det3_helper(a1, a3, a4, b1, b3, b4, c1, c3, c4) * di;
      tmp.data_[ 8] =  det3_helper(b1, b2, b4, c1, c2, c4, d1, d2, d4) * di;
      tmp.data_[ 9] = -det3_helper(a1, a2, a4, c1, c2, c4, d1, d2, d4) * di;
      tmp.data_[10] =  det3_helper(a1, a2, a4, b1, b2, b4, d1, d2, d4) * di;
      tmp.data_[11] = -det3_helper(a1, a2, a4, b1, b2, b4, c1, c2, c4) * di;
      tmp.data_[12] = -det3_helper(b1, b2, b3, c1, c2, c3, d1, d2, d3) * di;
      tmp.data_[13] =  det3_helper(a1, a2, a3, c1, c2, c3, d1, d2, d3) * di;
      tmp.data_[14] = -det3_helper(a1, a2, a3, b1, b2, b3, d1, d2, d3) * di;
      tmp.data_[15] =  det3_helper(a1, a2, a3, b1, b2, b3, c1, c2, c3) * di;
      
      swap(tmp);
      
      result = true;
    }

    return result;
  }

  void
  matrix::transpose()
  {
    matrix tmp(*this);

    // data_[ 0] = tmp.data_[ 0];
    data_[ 1] = tmp.data_[ 4];
    data_[ 2] = tmp.data_[ 8];
    data_[ 3] = tmp.data_[12];
    data_[ 4] = tmp.data_[ 1];
    // data_[ 5] = tmp.data_[ 5];
    data_[ 6] = tmp.data_[ 9];
    data_[ 7] = tmp.data_[13];
    data_[ 8] = tmp.data_[ 2];
    data_[ 9] = tmp.data_[ 6];
    // data_[10] = tmp.data_[10];
    data_[11] = tmp.data_[14];
    data_[12] = tmp.data_[ 3];
    data_[13] = tmp.data_[ 7];
    data_[14] = tmp.data_[11];
    // data_[15] = tmp.data_[15];
  }


  void 
  matrix::lr_decompose(matrix& l, matrix& r) const
  {    
    // initialise matrices
    r = *this;
    l = matrix::identity();

    // first row
    double const q1 = r[ab] / r[aa];
    double const q2 = r[ac] / r[aa];
    double const q3 = r[ad] / r[aa];

    r[ab] -= q1 * r[aa]; 
    r[bb] -= q1 * r[ba];
    r[cb] -= q1 * r[ca];
    r[db] -= q1 * r[da];

    r[ac] -= q2 * r[aa]; 
    r[bc] -= q2 * r[ba];
    r[cc] -= q2 * r[ca];
    r[dc] -= q2 * r[da];

    r[ad] -= q3 * r[aa]; 
    r[bd] -= q3 * r[ba];
    r[cd] -= q3 * r[ca];
    r[dd] -= q3 * r[da];

    l[ab] = q1;
    l[ac] = q2;
    l[ad] = q3;

    // second row
    double const q4 = r[bc] / r[bb];
    double const q5 = r[bd] / r[bb];
	
    r[bc] -= q4 * r[bb];
    r[cc] -= q4 * r[cb];
    r[dc] -= q4 * r[db];

    r[bd] -= q5 * r[bc];
    r[cd] -= q5 * r[cc];
    r[dd] -= q5 * r[dc];

    l[bc] = q4;
    l[bd] = q5;

    // third row
    double q6 = r[cd] / r[cc];
    r[cd] -= q6 * r[cc];
    r[dd] -= q6 * r[dc];
    l[cd]  = q6; 
  }

  bool
  matrix::is_invertible() const
  {
    return 0 != determinant();
  }

  /* static */
  matrix const& 
  matrix::null()
  {
    static matrix null_(null_array16);
    return null_;
  }
  
  /* static */
  matrix const& 
  matrix::identity()
  {
    static matrix identity_(ident_array16);
    return identity_;
  }

  matrix
  operator-(matrix const& rhs)
  {
    return matrix(rhs) *= -1.0;
  }

  matrix
  operator*(matrix const& lhs, matrix const& rhs)
  {
    return matrix(lhs) *= rhs;
  }

  matrix
  operator*(matrix const& lhs, double rhs)
  {
    return matrix(lhs) *= rhs;
  }

  matrix
  operator*(double lhs, matrix const& rhs)
  {
    return matrix(rhs) *= lhs;
  }

  matrix
  operator/(matrix const& lhs, double rhs)
  {
    return matrix(lhs) /= rhs;
  }
  
  point
  operator*(matrix const& lhs, const point& rhs)
  {
    return point(lhs[matrix::aa] * rhs[point::x] +
                 lhs[matrix::ba] * rhs[point::y] +
                 lhs[matrix::ca] * rhs[point::z] +
                 lhs[matrix::da] * rhs[point::w],
                 lhs[matrix::ab] * rhs[point::x] +
                 lhs[matrix::bb] * rhs[point::y] +
                 lhs[matrix::cb] * rhs[point::z] +
                 lhs[matrix::db] * rhs[point::w],
                 lhs[matrix::ac] * rhs[point::x] +
                 lhs[matrix::bc] * rhs[point::y] +
                 lhs[matrix::cc] * rhs[point::z] +
                 lhs[matrix::dc] * rhs[point::w],
                 lhs[matrix::ad] * rhs[point::x] +
                 lhs[matrix::bd] * rhs[point::y] +
                 lhs[matrix::cd] * rhs[point::z] +
                 lhs[matrix::dd] * rhs[point::w]);
  }
  
  vector
  operator*(matrix const& lhs, const vector& rhs)
  {
    return vector(lhs[matrix::aa] * rhs[vector::x] +
                  lhs[matrix::ba] * rhs[vector::y] +
                  lhs[matrix::ca] * rhs[vector::z] +
                  lhs[matrix::da] * rhs[vector::w],
                  lhs[matrix::ab] * rhs[vector::x] +
                  lhs[matrix::bb] * rhs[vector::y] +
                  lhs[matrix::cb] * rhs[vector::z] +
                  lhs[matrix::db] * rhs[vector::w],
                  lhs[matrix::ac] * rhs[vector::x] +
                  lhs[matrix::bc] * rhs[vector::y] +
                  lhs[matrix::cc] * rhs[vector::z] +
                  lhs[matrix::dc] * rhs[vector::w],
                  lhs[matrix::ad] * rhs[vector::x] +
                  lhs[matrix::bd] * rhs[vector::y] +
                  lhs[matrix::cd] * rhs[vector::z] +
                  lhs[matrix::dd] * rhs[vector::w]);
  }

  bool 
  operator==(matrix const& lhs, matrix const& rhs)
  {
  return (std::fabs(lhs[matrix::aa] - rhs[matrix::aa]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ba] - rhs[matrix::ba]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ca] - rhs[matrix::ca]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::da] - rhs[matrix::da]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::aa] - rhs[matrix::aa]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ba] - rhs[matrix::ba]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ca] - rhs[matrix::ca]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::da] - rhs[matrix::da]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::aa] - rhs[matrix::aa]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ba] - rhs[matrix::ba]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ca] - rhs[matrix::ca]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::da] - rhs[matrix::da]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::aa] - rhs[matrix::aa]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ba] - rhs[matrix::ba]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::ca] - rhs[matrix::ca]) < std::numeric_limits<double>::epsilon() &&
          std::fabs(lhs[matrix::da] - rhs[matrix::da]) < std::numeric_limits<double>::epsilon());  
  }

  matrix
  make_translation(double a, double b, double c)
  {
    matrix tmp;

    tmp[matrix::da] = a;
    tmp[matrix::db] = b;
    tmp[matrix::dc] = c;
    
    return tmp;
  }

  matrix
  make_translation(vector const& a)
  {
    return make_translation(a[vector::x], a[vector::y], a[vector::z]);
  }

  matrix
  make_scale(double a, double b, double c)
  {
    matrix tmp;

    tmp[matrix::aa] = a;
    tmp[matrix::bb] = b;
    tmp[matrix::cc] = c;
    
    return tmp;
  }

  matrix
  make_scale(vector const& a)
  {
    return make_scale(a[vector::x], a[vector::y], a[vector::z]);
  }

  matrix
  make_rotation_x(double a)
  {
    double const cos_a(std::cos(a));
    double const sin_a(std::sin(a));
    
    matrix tmp;

    tmp[matrix::bb] =  cos_a;
    tmp[matrix::cb] =  sin_a;
    tmp[matrix::bc] = -sin_a;
    tmp[matrix::cc] =  cos_a;
    
    return tmp;
  }

  matrix
  make_rotation_y(double a)
  {
    double const cos_a(std::cos(a));
    double const sin_a(std::sin(a));
    
    matrix tmp;

    tmp[matrix::aa] =  cos_a;
    tmp[matrix::ca] = -sin_a;
    tmp[matrix::ac] =  sin_a;
    tmp[matrix::cc] =  cos_a;
    
    return tmp;
  }

  matrix
  make_rotation_z(double a)
  {
    double const cos_a(std::cos(a));
    double const sin_a(std::sin(a));
    
    matrix tmp;

    tmp[matrix::aa] =  cos_a;
    tmp[matrix::ba] =  sin_a;
    tmp[matrix::ab] = -sin_a;
    tmp[matrix::bb] =  cos_a;
    
    return tmp;
  }

  double
  determinant(matrix const& a)
  {
    return a.determinant();
  }

  double
  trace(matrix const& a)
  {
    return a.trace();
  }
  
  matrix
  inverse(matrix const& a)
  {
    matrix tmp(a);

    tmp.invert();
    
    return tmp;
  }

  matrix
  transpose(matrix const& a)
  {
    matrix tmp(a);

    tmp.transpose();
    
    return tmp;
  }
  
  bool
  is_invertible(matrix const& a)
  {
    return a.is_invertible();
  }

  std::ostream&
  operator<<(std::ostream& os, matrix const& a)
  {
    std::ostream::sentry const cerberus(os);

    if (cerberus) {
      os << std::fixed << std::setprecision(3)
         << '['
         << a[matrix::aa] << ','
         << a[matrix::ba] << ','
         << a[matrix::ca] << ','
         << a[matrix::da] << ','
         << std::endl
         << ' '
         << a[matrix::ab] << ','
         << a[matrix::bb] << ','
         << a[matrix::cb] << ','
         << a[matrix::db] << ','
         << std::endl
         << ' '
         << a[matrix::ac] << ','
         << a[matrix::bc] << ','
         << a[matrix::cc] << ','
         << a[matrix::dc] << ','
         << std::endl
         << ' '
         << a[matrix::ad] << ','
         << a[matrix::bd] << ','
         << a[matrix::cd] << ','
         << a[matrix::dd]
         << ']';
    }

    return os;
  }
  
} // namespace math3d {

// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2008 Bauhaus University Weimar                                                   */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  vector.cpp                                                                      */
/*  project    :  lectures in programming && software engineering, winter 08/09                   */
/*  description:  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "vector.hpp"

// includes, system

#include <algorithm> // std::swap_ranges
#include <cmath>     // std::sqrt
#include <limits>    // std::numeric_limits
#include <ostream>   // std::ostream

// includes, project

#include <point.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace math3d {
  
  // variables, exported

  // functions, exported
  
  vector::vector()
  {
    data_[0] = data_[1] = data_[2] = data_[3] = 0.0;
  }
  
  vector::vector(vector const& a)
  {
    data_[0] = a.data_[0];
    data_[1] = a.data_[1];
    data_[2] = a.data_[2];
    data_[3] = a.data_[3];
  }

  vector::vector(point const& a, point const& b)
  {
    data_[0] = b[point::x] - a[point::x];
    data_[1] = b[point::y] - a[point::y];
    data_[2] = b[point::z] - a[point::z];
    data_[3] = 0.0;
  }
  
  vector::vector(double a, double b, double c, double d)
  {
    data_[0] = a;
    data_[1] = b;
    data_[2] = c;
    data_[3] = d;
  }

  vector::~vector()
  {}

  void
  vector::swap(vector& rhs)
  {
    std::swap_ranges(data_, data_+4, rhs.data_);
  }

  vector&
  vector::operator=(vector const& rhs)
  {
    vector tmp(rhs);

    swap(tmp);
    
    return *this;
  }

  double const&
  vector::operator[](vector::component idx) const
  {
    return data_[idx];
  }

  double&
  vector::operator[](vector::component idx)
  {
    return data_[idx];
  }

  vector&
  vector::operator+=(vector const& rhs)
  {
    data_[0] += rhs.data_[0];
    data_[1] += rhs.data_[1];
    data_[2] += rhs.data_[2];
    // data_[3] += rhs.data_[3];
    
    return *this;
  }

  vector&
  vector::operator-=(vector const& rhs)
  {
    data_[0] -= rhs.data_[0];
    data_[1] -= rhs.data_[1];
    data_[2] -= rhs.data_[2];
    // data_[3] -= rhs.data_[3];
    
    return *this;
  }

  vector&
  vector::operator*=(double rhs)
  {
    data_[0] *= rhs;
    data_[1] *= rhs;
    data_[2] *= rhs;
    data_[3] *= rhs;
    
    return *this;
  }

  vector&
  vector::operator/=(double rhs)
  {
    data_[0] /= rhs;
    data_[1] /= rhs;
    data_[2] /= rhs;
    data_[3] /= rhs;
    
    return *this;
  }
  
  vector
  operator-(vector const& rhs)
  {
    return vector(rhs) *= -1.0;
  }
  
  vector
  operator+(vector const& lhs, vector const& rhs)
  {
    return vector(lhs) += rhs;
  }

  vector
  operator-(point const& lhs, point const& rhs)
  {
    return vector(rhs, lhs);
  }
  
  vector
  operator-(vector const& lhs, vector const& rhs)
  {
    return vector(lhs) -= rhs;
  }

  vector
  operator*(vector const& lhs, double rhs)
  {
    return vector(lhs) *= rhs;
  }

  vector
  operator*(double lhs, vector const& rhs)
  {
    return vector(rhs) *= lhs;
  }

  vector
  operator/(vector const& lhs, double rhs)
  {
    return vector(lhs) /= rhs;
  }

 double operator*(vector const& lhs, vector const& rhs)
  {
	return (lhs[vector::x]*rhs[vector::x]+lhs[vector::y]*rhs[vector::y]+lhs[vector::z]+rhs[vector::z]);
  }
  
  /* static */ vector const&
  vector::null() 
  {
    static vector null_(0.0, 0.0, 0.0);
    return null_;
  }

  /* static */ vector const&
  vector::unit_x()
  {
    static vector unit_x_(1.0, 0.0, 0.0); 
    return unit_x_;
  }

  /* static */ vector const&
  vector::unit_y()
  {
    static vector unit_y_(0.0, 1.0, 0.0); 
    return unit_y_;
  }

  /* static */ vector const&
  vector::unit_z()
  {
    static vector unit_z_(0.0, 0.0, 1.0); 
    return unit_z_;
  }
  
  std::ostream&
  operator<<(std::ostream& os, vector const& a)
  {
    std::ostream::sentry const cerberus(os);

    if (cerberus) {
      os << '['
         << a[vector::x] << ','
         << a[vector::y] << ','
         << a[vector::z] << ','
         << a[vector::w]
         << ']';
    }

    return os;
  }

  bool    
  operator==(vector const& lhs, vector const& rhs) 
  {
  return (std::fabs(rhs[vector::x] - lhs[vector::x]) < std::numeric_limits<double>::epsilon() && 
          std::fabs(rhs[vector::y] - lhs[vector::y]) < std::numeric_limits<double>::epsilon() && 
          std::fabs(rhs[vector::z] - lhs[vector::z]) < std::numeric_limits<double>::epsilon());          
  }
  
} // namespace math3d {


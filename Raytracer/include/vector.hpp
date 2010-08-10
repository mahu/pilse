// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2008 Bauhaus University Weimar                                                   */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  vector.hpp                                                                      */
/*  project    :  lectures in programming && software engineering, winter 08/09                   */
/*  description:  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(BUW_MATH3D_VECTOR_HPP)

#define BUW_MATH3D_VECTOR_HPP

// includes, system
#include <iosfwd> // fwd. decl: std::ostream

// includes, project

namespace math3d {

  // types, exported (class, enum, struct, union, typedef)
  
  class point;
  
  class vector {
    
  public:

    enum component { x = 0, y = 1, z = 2, w = 3 };
    
    vector();
    vector(vector const&);
    vector(point const&, point const&);           // second - first
    vector(double, double, double, double = 0.0); // x, y, z, w
    
    ~vector();

    void swap(vector&);
    
    vector& operator=(vector const&);
    
    double const& operator[](component) const;
    double&       operator[](component);
    
    vector& operator+=(vector const&);
    vector& operator-=(vector const&);
    vector& operator*=(double);
    vector& operator/=(double);
      
    static vector const& null();   // v[0,0,0,0]
    static vector const& unit_x(); // v[1,0,0,0]
    static vector const& unit_y(); // v[0,1,0,0]
    static vector const& unit_z(); // v[0,0,1,0]


  private:
    
    double data_[4];
    
  };
  
  // variables, exported (extern)
  
  // functions, inlined (inline)
  
  // functions, exported (extern)
    vector operator-(vector const&);
  
  vector operator+(vector const&, vector const&);
  vector operator-(point const&, point const&);
  vector operator-(vector const&, vector const&);
  vector operator*(vector const&, double);
  vector operator*(double, vector const&);
  vector operator/(vector const&, double);
  bool   operator==(vector const&, vector const&);

  std::ostream& operator<<(std::ostream&, vector const&);
  
} // namespace math3d {

#endif // #if !defined(BUW_MATH3D_VECTOR_HPP)


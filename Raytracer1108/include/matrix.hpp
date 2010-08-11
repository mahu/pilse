// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2008 Bauhaus University Weimar                                                   */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  matrix.hpp                                                                      */
/*  project    :  lectures in programming && software engineering, winter 08/09                   */
/*  description:  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(BUW_MATH3D_MATRIX_HPP)

#define BUW_MATH3D_MATRIX_HPP

// includes, system
#include <iosfwd> // fwd. decl: std::ostream

// includes, project
#include <vector.hpp>

namespace math3d {

  // types, exported (class, enum, struct, union, typedef)

  class point;
  
  class matrix {

  public:
    
    enum cols { c0 = vector::x, c1 = vector::y, c2 = vector::z, c3 = vector::w };
    enum rows { r0 = vector::x, r1 = vector::y, r2 = vector::z, r3 = vector::w };

    // column major element ordering
    enum component { aa =  0, ba =  4, ca =  8, da = 12,
                     ab =  1, bb =  5, cb =  9, db = 13,
                     ac =  2, bc =  6, cc = 10, dc = 14,
                     ad =  3, bd =  7, cd = 11, dd = 15 };
    
    matrix();
    matrix(matrix const&);
    matrix(double const [16]);

    ~matrix();

    void swap(matrix&);
    
    matrix& operator=(matrix const&);

    double const& operator()(cols, rows) const;
    double&       operator()(cols, rows);

    double const& operator[](component) const;
    double&       operator[](component);
    
    matrix& operator*=(matrix const&);
    matrix& operator*=(double);
    matrix& operator/=(double);
    
    double trace() const;
    
    // to implement
    double determinant() const;

    bool invert();

    bool is_invertible() const; // det(M) != 0

    static matrix const& null();     // m[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    static matrix const& identity(); // m[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]
    
  private:

    double data_[16];

  };

  // variables, exported (extern)
  
  // functions, inlined (inline)
  
  // functions, exported (extern)

  matrix operator-(matrix const&);
  
  matrix operator*(matrix const&, matrix const&);
  matrix operator*(matrix const&, double);
  matrix operator*(double, matrix const&);
  matrix operator/(matrix const&, double);
  
  point  operator*(matrix const&, point const&);
  vector operator*(matrix const&, vector const&);

  bool operator==(matrix const&, matrix const&);

  matrix make_rotation_x(double);

  double determinant(matrix const&);
  double trace(matrix const&);
  matrix inverse(matrix const&);
  matrix transpose(matrix const&);

  bool is_invertible(matrix const&);
  
  std::ostream& operator<<(std::ostream&, matrix const&);

} // namespace math3d {

#endif // #if !defined(BUW_MATH3D_MATRIX_HPP)

/******************************************************************************
 * Declaration of a matrix object                                             *
 * CMatrix.h                                                                  *
 *                                                                            *
 * Module: "Embedded Systems II" - Uebung 3-03                                *
 *                                                                            *
 * Hochschule Mittweida, INW                                                  *
 * Prof. J. Thomanek                                                          *
 *                                                                            *
 ******************************************************************************/
#pragma once

 // ---------------------------------------------------------------------------
 //  C O N S T A N T S
 // ---------------------------------------------------------------------------

// Dimension of the matrix
const int N_ROW = 3;
const int N_COL = 3;


// ----------------------------------------------------------------------------
//  C L A S S     D E C L R A T I O N
// ----------------------------------------------------------------------------
class CMatrix {

public:
	// --------------------------------------------------------------
	//  C o n s t r u c t o r s   D e c l a r a t i o n
	// --------------------------------------------------------------
	CMatrix();
	CMatrix(double s);
	CMatrix(const double* a);
	CMatrix(const CMatrix& m);

	// --------------------------------------------------------------
	//  P u b l i c   M e t h o d s   De c l a r a t i o n
	// --------------------------------------------------------------
	// Matrix element access
	double GetElement(int r, int c) const;
	void SetElement(int r, int c, double v);

	// Scalar operations
	void AddScalar(double s);
	void MulScalar(double s);

	// Matrix operations
	void Plus(CMatrix& m);
	CMatrix Add(CMatrix& m) const;
	CMatrix Mul(const CMatrix& m) const;

	// Transpose Matrix
	void Transpose();

	
private:
    // Matrix Data Array
	double m_f64Data[N_ROW * N_COL];
};
#include "lab1.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter the number of equations: ";
	cin >> n;
	cout << endl;
	cout << "Enter the coefficient matrix line by line:" << endl;
	vector<vector<double> > a;
	a.resize(n);
	double x;
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j) {
			cin >> x;
			a[i].push_back(x);
		}
	}
	cout << "Enter the column of constants: " << endl;
	vector<double> b;
	for (int i(0); i < n; ++i) {
		cin >> x;
		b.push_back(x);
	}
	cout << endl;
	SLAE S(a, b);
	
	vector<vector<double> > mat;

	cout << "Choose the method:" << endl << "1 - rotation method" << endl << "2 - LU-decomposition" << endl
		<< "3 - find inverse matrix" << endl << "4 - inverse matrix method" << endl
		<< "5 - square roots method" << endl << "6 - find eigenvalues by LU-decomposition" << endl
		<< "7 - conjugate gradient method" << endl << "8 - find min eigenvalue" << endl;
	int meth;
	cin >> meth;
	switch (meth)
	{
	case 1:
		cout << "Rotation method: " << endl;
		S.rotationMethod();
		cout << "Solution:" << endl;
		for (int i(0); i < n; ++i) {
			cout << "x" << i + 1 << " = " << S.solution[i] << endl;
		}
		break;
	case 2:
		cout << "LU-decomposition method: " << endl;
		S.LUsolution();
		
		cout << "Matrix L:" << endl;
		for (int i(0); i < n; ++i) {
			for (int j(0); j < n; ++j) {
				cout << S.L[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << "Matrix U:" << endl;
		for (int i(0); i < n; ++i) {
			for (int j(0); j < n; ++j) {
				cout << S.U[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Solution:" << endl;
		for (int i(0); i < n; ++i) {
			cout << "x" << i + 1 << " = " << S.solution[i] << endl;
		}
		break;
	case 3:
		cout << "Inverse matrix:" << endl;
		mat = S.inverseMatrix();
		for (int i(0); i < n; ++i) {
			for (int j(0); j < n; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		break;
	case 4:
		cout << "Inverse matrix method: " << endl;
		S.invMatMethod();
		cout << "Solution:" << endl;
		for (int i(0); i < n; ++i) {
			cout << "x" << i + 1 << " = " << S.solution[i] << endl;
		}
		break;
	case 5:
		cout << "Square roots method: " << endl;
		S.sqRootsMethod();
		cout << "Solution:" << endl;
		for (int i(0); i < n; ++i) {
			cout << "x" << i + 1 << " = " << S.solution[i] << endl;
		}
		break;
	case 6:
		cout << "Eigenvalues: " << endl;
		S.eigenValuesLU();
		for (int i(0); i < n; ++i) {
			cout << "lambda" << i + 1 << " = " << S.eigenValues[i] << endl;
			cout << "v" << i + 1 << ": ";
			for (int j(0); j < n; ++j) {
				cout << S.eigenVectors[i][j] << " ";
			}
			cout << endl;
		}
		break;
	case 7:
		cout << "Conjugate gradient method: " << endl;
		S.conjugateGradientMethod();
		cout << "Solution:" << endl;
		for (int i(0); i < n; ++i) {
			cout << "x" << i + 1 << " = " << S.solution[i] << endl;
		}
		break;
	case 8:
		cout << "Minimum eigenvalue: " << S.minEigenValue() <<endl;
		cout << "Minimum eigenvector: " << endl;
		for (int j(0); j < n; ++j) {
			cout << S.eigenVector(S.minEigenValue())[j] << " ";
		}
		cout << endl;
		break;
	default:
		break;
	}
	return 0;
}
# include "iostream"
using namespace std;

template <typename DATA>
class Matrix{
    
    private:
        size_t rows, cols;
        DATA** mat;

    public:
        Matrix(); // Empty Constructor = Calls when declaring an array.
        Matrix(size_t, size_t); // Constructor
        Matrix(const Matrix<DATA> &); // Copy Constructor
        Matrix(Matrix<DATA> &&); // Move Constructor
        ~Matrix(); // Destructor
        void fill(DATA);
        void clear();
        void accept();
        DATA * operator[] (size_t);
        const DATA * operator[] (const size_t) const;
        void display() const;
        size_t getRows() const;
        size_t getCols() const;
        size_t getSize() const;
        void displayDims() const;
        bool contains(DATA) const;
        bool isSquared() const;
        bool isUpperTriangular() const;
        bool isLowerTriangular() const;
        bool isSymmetric() const;
        bool isSkewSymmetric() const;
        Matrix<DATA> transpose() const;
        void displayTranspose() const;
        Matrix<DATA> operator+(const Matrix<DATA> &) const;
        Matrix<DATA> operator-(const Matrix<DATA> &) const;
        Matrix<DATA> operator*(const Matrix<DATA> &) const;
        Matrix<DATA> operator+=(const Matrix<DATA> &);
        Matrix<DATA> operator-=(const Matrix<DATA> &);

        Matrix<DATA>& operator=(const Matrix<DATA>&); // Copy Assignment
        Matrix<DATA>& operator=(Matrix<DATA>&&); // Move Assignment
};


template <typename DATA> 
Matrix<DATA> :: Matrix()
    :rows(0), cols(0), mat(nullptr) {}

template <typename DATA>
Matrix<DATA> :: Matrix(size_t r, size_t c)
    :rows(r), cols(c){
        mat = new DATA* [rows];
        for (size_t i = 0; i < rows; i++)
        {
            mat[i] = new DATA[cols];
        }
    }

template <typename DATA>
Matrix<DATA> :: Matrix(const Matrix<DATA>& lMatrix){

    cout << "In copy constructor" << endl;
    rows = lMatrix.getRows();
    cols = lMatrix.getCols();

    mat = new DATA* [rows];
    for (size_t i = 0; i < rows; i++)
        mat[i] = new DATA[cols];

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            mat[i][j] = lMatrix[i][j];
        }
    }
}

template <typename DATA>
Matrix<DATA> :: Matrix(Matrix<DATA> && rMatrix)
    :rows(rMatrix.rows), cols(rMatrix.cols), mat(rMatrix.mat){
        cout << "In move constructor" << endl;
        // delete[] rMatrix.mat;
    }

template <typename DATA>
Matrix<DATA> :: ~Matrix(){
    for (size_t i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;
}


template <typename DATA>
void Matrix<DATA> :: fill(DATA val){
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            mat[i][j] = val;   
}

template <typename DATA>
void Matrix<DATA> :: clear(){
    fill(0);
}

template <typename DATA>
void Matrix<DATA> :: accept(){
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "Enter the element at index " << i << " * " << j << " : ";
            cin >> mat[i][j];
        }
    }
}

template <typename DATA>
DATA * Matrix<DATA> :: operator[](size_t index){
    return mat[index];
}

template <typename DATA>
const DATA* Matrix<DATA> :: operator[] (const size_t index) const{
    return mat[index];
}

template <typename DATA>
void Matrix<DATA> :: display() const{
    cout << "Printing the Matrix: " << endl;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

template <typename DATA>
size_t Matrix<DATA> :: getRows() const{
    return rows;
}

template <typename DATA>
size_t Matrix<DATA> :: getCols() const{
    return cols;
}

template <typename DATA>
size_t Matrix<DATA> :: getSize() const{
    return rows * cols;
}

template <typename DATA>
void Matrix<DATA> :: displayDims() const{
    cout << "Rows: " << rows << "\t" << "Cols: " << cols << endl;
}

template <typename DATA>
bool Matrix<DATA> :: contains(DATA val) const{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (mat[i][j] == val)
                return true;

    return false;
}

template <typename DATA>
bool Matrix<DATA> :: isSquared() const{
    if (rows == cols){
        cout << "Matrix is squared!" << endl;
        return true;
    }
    return false;
}

template <typename DATA>
bool Matrix<DATA> :: isUpperTriangular() const{
    if (!isSquared()){
        cout << "Matrix is not upper triangular." << endl;
    }

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (i < j)
                if (mat[i][j] != 0){
                    cout << "Matrix is not upper triangular." << endl;
                    return false;
                }
    
    cout << "Matrix is upper triangular." << endl;
    return true;
}

template <typename DATA>
bool Matrix<DATA> :: isLowerTriangular() const{
    if (!isSquared()){
        cout << "Matrix is not lower triangular." << endl;
    }

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (i > j)
                if (mat[i][j] != 0){
                    cout << "Matrix is not lower triangular." << endl;
                    return false;
                }
    
    cout << "Matrix is lower triangular." << endl;
    return true;
}

template <typename DATA>
Matrix<DATA> Matrix<DATA> :: transpose() const{
    Matrix<DATA> trans(cols, rows);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            trans[j][i] = mat[i][j];
    return trans;
}

template <typename DATA>
void Matrix<DATA> :: displayTranspose() const{
    cout << "Transpose of the Matrix: " << endl;
    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
            cout << mat[j][i] << "\t";
        cout << endl;
    }
}

template <typename DATA>
bool Matrix<DATA> :: isSymmetric() const{
    if (!isSquared()){
        cout << "Matrix is not symmetric." << endl;
        return false;
    }

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (mat[i][j] != mat[j][i]){
                cout << "Matrix is not symmetric." << endl;
                return false;
            }

    cout << "Matrix is symmetric!" << endl;
    return true;
}

template <typename DATA>
bool Matrix<DATA> :: isSkewSymmetric() const{
    if (!isSquared()){
        cout << "Matrix is not skew-symmetric." << endl;
        return false;
    }

    for (size_t i = 0; i < rows; i++)
        if (mat[i][i] != 0){
            cout << "Matrix is not skew-symmetric." << endl;
            return false;
        }

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (mat[i][j] != -mat[j][i]){
                cout << "Matrix is not skew-symmetric." << endl;
                return false;
            }
            
    cout << "Matrix is skew-symmetric." << endl;
    return true;
}

template <typename DATA>
Matrix<DATA> Matrix<DATA> :: operator+(const Matrix<DATA> & rightMat) const{
    if (rows != rightMat.getRows()){
        cout << "Error: Rows doesn't match" << endl;
        return Matrix<DATA>();
    }

    if (cols != rightMat.getCols()){
        cout << "Error: Columns doesn't match" << endl;
        return Matrix<DATA>();
    }

    Matrix<DATA> temp(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            temp[i][j] = mat[i][j] + rightMat[i][j];
        }
    }

    return temp;
}

template <typename DATA>
Matrix<DATA> Matrix<DATA> :: operator+=(const Matrix<DATA> & rightMat){
    if (rows != rightMat.getRows()){
        cout << "Error: Rows doesn't match" << endl;
        return Matrix<DATA>();
    }

    if (cols != rightMat.getCols()){
        cout << "Error: Columns doesn't match" << endl;
        return Matrix<DATA>();
    }

    // The following expression is alone sufficient to perform +=
    // *this = *this + rightMat; 
    // return *this;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            mat[i][j] = mat[i][j] + rightMat[i][j];
        }
    }

    return *this;
}


template <typename DATA>
Matrix<DATA> Matrix<DATA> :: operator-(const Matrix<DATA> & rightMat) const{
    if (rows != rightMat.getRows()){
        cout << "Error: Rows doesn't match" << endl;
        return Matrix<DATA>();
    }

    if (cols != rightMat.getCols()){
        cout << "Error: Columns doesn't match" << endl;
        return Matrix<DATA>();
    }

    Matrix<DATA> temp(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            temp[i][j] = mat[i][j] - rightMat[i][j];
        }
    }

    return temp;
}

template <typename DATA>
Matrix<DATA> Matrix<DATA> :: operator-=(const Matrix<DATA> & rightMat){
    // if (rows != rightMat.getRows()){
    //     cout << "Error: Rows doesn't match" << endl;
    //     return Matrix<DATA>();
    // }

    // if (cols != rightMat.getCols()){
    //     cout << "Error: Columns doesn't match" << endl;
    //     return Matrix<DATA>();
    // }

    // Matrix<DATA> temp(rows, cols);
    // for (size_t i = 0; i < rows; i++)
    // {
    //     for (size_t j = 0; j < cols; j++)
    //     {
    //         temp[i][j] = mat[i][j] - rightMat[i][j];
    //     }
    // }

    // return temp;
    *this = *this - rightMat;
    return *this;
}


template <typename DATA>
Matrix<DATA> Matrix<DATA> :: operator*(const Matrix<DATA> & rightMat) const{
    if (cols != rightMat.getRows()){
        cout << "Error: Multiplication is not possible" << endl;
        return Matrix<DATA>();
    }

    Matrix<DATA> temp(rows, rightMat.getCols());
    temp.fill(0);
    DATA total = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rightMat.getCols(); j++)
        {
            total = 0;
            for (size_t k = 0; k < cols; k++)
            {
                total += (mat[i][k] * rightMat[k][j]);
            }
            temp[i][j] = total;
        }
    }

    return temp;
}

template <typename DATA>
Matrix<DATA>& Matrix<DATA>::operator=(const Matrix<DATA>& lMatrix){
    if ((rows != lMatrix.getRows()) && (cols != lMatrix.getCols())){
        cout << "ERROR :: Dimensions do not match!" << endl;
        return *this;
    }

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            mat[i][j] = lMatrix[i][j];
    
    return *this;
}

template <typename DATA>
Matrix<DATA>& Matrix<DATA>::operator=(Matrix<DATA>&& rMatrix){
    if ((rows != rMatrix.rows) && (cols != rMatrix.getCols())){
        cout << "ERROR :: Dimensions do not match!" << endl;
        return *this;
    }
    mat = rMatrix.mat;
    return *this;
}



int main(int argc, char const *argv[])
{
    cout << "Hello, World!" << endl;
    // int option,ch;
    // int & optionRef = option;
    
    // Matrix<int> mat(3,3);
    // do{
    //     cout<<"1.Accept the matrix"<<endl;
    //     cout<<"2.Display the matrix"<<endl;
    //     cout<<"3.Contains the element"<<endl;
    //     cout<<"4.Is square matrix"<<endl;
    //     cout<<"5.Is upper triangular matrix"<<endl;
    //     cout<<"6.Is lower triangular matrix"<<endl;
    //     cout<<"7.Is symmetric matrix"<<endl;
    //     cout<<"8.Is skew symmetric matrix"<<endl;
    //     cout<<"9.Transpose of a matrix"<<endl;
    //     cout<<"10.Addition of two matrices"<<endl;
    //     cout<<"11.Multiplication of two matrices"<<endl;
    //     cout<<"12.Subtraction of two matrices"<<endl;
    //     cin>>option;
    //     switch(option)
    //     {
    //         case 1: 
    //             mat.accept();
    //             break;
    //         case 2:
    //             mat.display();
    //             break;
    //         case 3:
    //             mat.contains(5);
    //             break;
    //         case 4: 
    //             mat.isSquared();
    //             break;
    //         case 5:
    //             mat.isUpperTriangular();
    //             break;
    //         case 6:
    //             mat.isLowerTriangular();
    //             break;
    //         case 7:
    //             mat.isSymmetric();
    //             break;
    //         case 8:
    //             mat.isSkewSymmetric();
    //             break;
    //         case 9:
    //             mat.transpose();
    //             break;
    //      }
    //     cout<<"Do you want to continue, if yes press 1: "<<endl;
    //     cin>>ch;

    // }while(ch != 0);

    // Matrix<int> x(3, 3);
    // x.fill(3);

    // Matrix<int> y(x);
    // Matrix<int> y(std::move(x));

    // y.display();
    // y.fill(1);

    // x.display();
    // x.fill(9);

    // y.display();
    // x.display();

    // Matrix<int> z(Matrix<int>(4, 4));
    
    Matrix<int> x(3, 3);
    x.fill(5);
    x.display();

    Matrix<int> y(3, 3);
    y.fill(20);
    y.display();

    y = move(x);

    y.display();
    x.display();

    y.fill(-3);
    x.display();
    y.display();

    x.clear();
    x.display();
    y.display();

    return 0;
}

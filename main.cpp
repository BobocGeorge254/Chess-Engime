#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template <typename T>
T maximum(T A, T B) {
    if ( A > B )
        return A ;
    else return B ;
}

template <typename T>
T minimum(T A, T B) {
    if ( A > B )
        return B ;
    else return A ;
}

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

float WhiteKingMatrix[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
        {0,-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
        {0,-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
        {0,-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
        {0,-2.0,-3.0,-3.0,-4.0,-4.0,-3.0,-3.0,-2.0},
        {0,-1.0,-2.0,-2.0,-2.0,-2.0,-2.0,-2.0,-1.0},
        {0,2.0,2.0,0.0,0.0,0.0,0.0,2.0,2.0},
        {0,2.0,3.0,1.0,0.0,0.0,1.0,3.0,2.0}

};

float WhiteQueenMatrix[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,-2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0},
        {0,-1.0,0,0,0,0,0,0,-1.0},
        {0,-1.0,0,0.5,0.5,0.5,0.5,0,-1.0},
        {0,-0.5,0,0.5,0.5,0.5,0.5,0,-0.5},
        {0,0,0,0.5,0.5,0.5,0.5,0,0},
        {0,-1.0,0,0.5,0.5,0.5,0.5,0,-1.0},
        {0,-1.0,0,0.5,0.5,0.5,0.5,0,-1.0},
        {0,-2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0}

};

float WhiteRookMatrix[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0.5,1,1,1,1,1,1,0.5},
        {0,-0.5,0,0,0,0,0,0,-0.5},
        {0,-0.5,0,0,0,0,0,0,-0.5},
        {0,-0.5,0,0,0,0,0,0,-0.5},
        {0,-0.5,0,0,0,0,0,0,-0.5},
        {0,-0.5,0,0,0,0,0,0,-0.5},
        {0,0,0,0,0.5,0.5,0,0,0}

};

float WhiteBishopMatrix[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,-2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0},
        {0,-1.0,0,0,0,0,0,0,-1.0},
        {0,-1.0,0,0.5,1.0,1.0,0.5,0,-1.0},
        {0,-1.0,0.5,0.5,1.0,1.0,0.5,0.5,-1.0},
        {0,-1.0,0,1.0,1.0,1.0,1.0,0,-1.0},
        {0,-1.0,1.0,1.0,1.0,1.0,1.0,1.0,-1.0},
        {0,-1.0,0.5,0,0,0,0,0.5,-1.0},
        {0,-2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0}

};

float WhiteKnightMatrix[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,-5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0},
        {0,-4.0,-2.0,0,0,0,0,-2.0,-4.0},
        {0,-3.0,0,1.0,1.5,1.5,1.0,0,-3.0},
        {0,-3.0,0.5,1.5,2.0,2.0,1.5,0.5,-3.0},
        {0,-3.0,0,1.5,2.0,2.0,1.5,0,-3.0},
        {0,-3.0,0.5,1.0,1.5,1.5,1.0,0.5,-3.0},
        {0,-4.0,-2.0,0,0.5,0.5,0,-2.0,-4.0},
        {0,-5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0}
};

float WhitePawnMatrix[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,5.0,5.0,5.0,5.0,5.0,5.0,5.0,5.0},
        {0,1.0,1.0,2.0,3.0,3.0,2.0,1.0,1.0},
        {0,0.5,0.5,1.0,2.5,2.5,1.0,0.5,0.5},
        {0,0,0,0,2.0,2.0,0,0,0},
        {0,0.5,-0.5,-1.0,0,0,-1.0,-0.5,0.5},
        {0,0.5,1.0,1.0,-2.0,-2.0,1.0,1.0,0.5},
        {0,0,0,0,0,0,0,0,0}
};

void CopyMatrix(float A[][9], float B[][9]) {
    for ( int i = 1 ; i <= 8 ; ++i )
        for ( int j = 1 ; j <= 8 ; ++j )
            B[i][j] = A[i][j] ;
    for ( int i = 1 ; i <= 4 ; ++i )
        for ( int j = 1 ; j <= 8 ; ++j )
            swap ( B[i][j] , B[8 - i + 1][j]) ;
}


float BlackKingMatrix[9][9] ;
float BlackQueenMatrix[9][9] ;
float BlackRookMatrix[9][9] ;
float BlackBishopMatrix[9][9] ;
float BlackKnightMatrix[9][9] ;
float BlackPawnMatrix[9][9] ;

bool Inside(int dx, int dy) {
    return (dx >= 1 && dx <= 8 && dy >= 1 && dy <= 8) ;
}

class Piece {
public:
    int positionX ;
    int positionY ;
    string name ;
    string color ;
    bool moved ;
    unordered_set < pair < int, int >, pair_hash > LegalMoves ;
public :
    Piece() ;
    virtual void GetLegalMoves() ;
    friend ostream& operator<< (ostream& out, Piece &piece) ;

}*Board[9][9];

void Piece::GetLegalMoves() {
    throw "error" ;
}

Piece::Piece() {
    this -> name = "" ;
    this -> color = "" ;
    this -> positionX = 0 ;
    this -> positionY = 0 ;

}

ostream& operator << (ostream& out, Piece &piece) {
    out << piece.name << " " ;
    out << piece.color << " " ;
    out << piece.positionX << " " ;
    out << piece.positionY << " " ;
    return out ;
}


pair <int, int> GetKingPosition (string color);
unordered_set <Piece*  > WhitePieces ;
unordered_set <Piece*> BlackPieces ;
bool Check(string,int,int) ;


/// PAWN-----------------------------------------------------------------
class Pawn : public Piece {
public :
    Pawn(string,int,int,bool) ;
    void GetLegalMoves() ;
};

Pawn::Pawn(string color, int positionX , int positionY ,bool moved = false) {
    this -> name = "Pawn" ;
    this -> color = color ;
    this -> moved = moved ;
    this -> positionX = positionX ;
    this -> positionY = positionY ;
}

void Pawn::GetLegalMoves() {
    unordered_set < pair < int , int >, pair_hash > LegalMoves = {} ;
    if ( this->color == "White" && this -> positionX == 2 ) {
        if ( Board[3][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(3, positionY) );
        if ( Board[4][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(4, positionY) );
    }
    if ( this->color == "Black" && this -> positionX == 7 ) {
        if ( Board[6][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(6, positionY) );
        if ( Board[5][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(5, positionY) );
    }
    if ( this -> color == "White" ) {
        if (Board[this->positionX + 1][this -> positionY]  == nullptr)
            LegalMoves.insert(make_pair(this -> positionX + 1, this -> positionY)) ;
        if (Inside( this -> positionX + 1, this -> positionY + 1) && Board[this -> positionX + 1][this -> positionY + 1] != nullptr && Board[this -> positionX + 1][this -> positionY + 1] -> color == "Black")
            LegalMoves.insert(make_pair(this -> positionX + 1, this -> positionY + 1) ) ;
        if (Inside( this -> positionX + 1, this -> positionY - 1) && Board[this -> positionX + 1][this -> positionY - 1] != nullptr && Board[this -> positionX + 1][this -> positionY - 1] -> color == "Black")
            LegalMoves.insert(make_pair(this -> positionX + 1, this -> positionY - 1) ) ;
    }
    if ( this -> color == "Black" ) {
        if (Board[this->positionX - 1][this -> positionY]  == nullptr)
            LegalMoves.insert(make_pair(this -> positionX - 1, this -> positionY)) ;
        if (Inside(this-> positionX - 1, this -> positionY + 1) && Board[this -> positionX - 1][this -> positionY + 1] != nullptr && Board[this -> positionX - 1][this -> positionY + 1] -> color == "White")
            LegalMoves.insert(make_pair(this -> positionX - 1, this -> positionY + 1) ) ;
        if (Inside(this -> positionX - 1, this -> positionY - 1) && Board[this -> positionX - 1][this -> positionY - 1] != nullptr && Board[this -> positionX - 1][this -> positionY - 1] -> color == "White")
            LegalMoves.insert(make_pair(this -> positionX - 1, this -> positionY - 1) ) ;
    }

    this -> LegalMoves = LegalMoves ;
}
/// PAWN-----------------------------------------------------------------


/// KNIGHT-----------------------------------------------------------------
int dx[] = {-2,-2,-1,-1,1,1,2,2} ;
int dy[] = {1,-1,2,-2,2,-2,1,-1};
class Knight : public Piece {
public :
    Knight(string,int,int) ;
    void GetLegalMoves() ;
};

Knight::Knight(string color,int positionX, int positionY) {
    this -> name = "Knight" ;
    this -> color = color ;
    this -> positionX = positionX ;
    this -> positionY = positionY ;
}

void Knight::GetLegalMoves() {
    unordered_set < pair < int , int >, pair_hash > LegalMoves = {} ;
    for ( int i = 0 ; i < 8 ; ++i ) {
        int newX = this -> positionX + dx[i] ;
        int newY = this -> positionY + dy[i] ;
        if ( Inside(newX, newY ) ) {
            if ( Board[newX][newY] == nullptr || ( Board[this -> positionX][this -> positionY]->color != Board[newX][newY] -> color) )
                LegalMoves.insert(make_pair(newX,newY)) ;
        }
    }
    this -> LegalMoves = LegalMoves ;
}
/// KNIGHT-----------------------------------------------------------------


class Bishop : public Piece {
public :
    Bishop(string,int,int) ;
    void GetLegalMoves() ;

};

Bishop::Bishop(string color,int positionX, int positionY){
    this -> name = "Bishop" ;
    this -> color = color ;
    this -> positionX = positionX ;
    this -> positionY = positionY ;
}

void Bishop::GetLegalMoves() {
    unordered_set < pair < int , int >, pair_hash > LegalMoves = {} ;

    ///to the top right
    for ( int i = this -> positionX + 1, j = this -> positionY + 1; Inside(i,j) ; ++i, ++j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if (Board[i][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][j]->color != Board[this->positionX][this->positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }


    ///to the bottom right
    for ( int i = this -> positionX - 1, j = this -> positionY + 1; Inside(i,j) ; --i, ++j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if (Board[i][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][j]->color != Board[this->positionX][this->positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }

    ///to the top left
    for ( int i = this -> positionX - 1, j = this -> positionY - 1; Inside(i,j) ; --i, --j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if (Board[i][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][j]->color != Board[this->positionX][this->positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }

    ///to the bottom left
    for ( int i = this -> positionX + 1, j = this -> positionY - 1; Inside(i,j) ; ++i, --j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if ( Board[i][j]->color == Board[this -> positionX][this -> positionY]->color)
                break ;
            if ( Board[i][j]->color != Board[this -> positionX][this -> positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }

    this -> LegalMoves = LegalMoves ;
}

class Rook : public Piece {
public :
    Rook(string,int,int,bool) ;
    void GetLegalMoves() ;

};

Rook::Rook(string color, int positionX, int postitionY, bool moved = false) {
    this -> name = "Rook" ;
    this -> moved = moved ;
    this -> color = color ;
    this -> positionX = positionX ;
    this -> positionY = postitionY ;
}

void Rook::GetLegalMoves() {

    unordered_set < pair < int , int >, pair_hash > LegalMoves = {} ;
    ///to the right
    for ( int j = this -> positionY + 1 ; Inside(this->positionX,j) ; ++j ) {
        if ( Board[this -> positionX][j] == nullptr )
            LegalMoves.insert(make_pair(this->positionX, j));
        else {
            if (Board[this->positionX][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[this->positionX][j]->color != Board[this->positionX][this->positionY]->color &&
                Board[this->positionX][j]->color != "") {
                LegalMoves.insert(make_pair(this->positionX, j));
                break;
            }
        }

    }

    ///to the left
    for ( int j = this -> positionY - 1 ; Inside(this->positionX,j) ; --j ) {
        if ( Board[this -> positionX][j] == nullptr )
            LegalMoves.insert(make_pair(this->positionX, j));
        else {
            if (Board[this->positionX][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[this->positionX][j]->color != Board[this->positionX][this->positionY]->color &&
                Board[this->positionX][j]->color != "") {
                LegalMoves.insert(make_pair(this->positionX, j));
                break;
            }
        }

    }

    ///to the bottom
    for ( int i = this -> positionX + 1; Inside(i,this->positionY) ; ++i ) {
        if ( Board[i][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(i, this -> positionY));
        else {
            if (Board[i][this->positionY]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][this->positionY]->color != Board[this->positionX][this->positionY]->color &&
                Board[i][this->positionY]->color != "") {
                LegalMoves.insert(make_pair(i, this->positionY));
                break;
            }
        }

    }

    ///to the top
    for ( int i = this -> positionX - 1 ; Inside(i,this->positionY) ; --i ) {
        if ( Board[i][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(i, this -> positionY));
        else {
            if (Board[i][this->positionY]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][this->positionY]->color != Board[this->positionX][this->positionY]->color &&
                Board[i][this->positionY]->color != "") {
                LegalMoves.insert(make_pair(i, this->positionY));
                break;
            }
        }
    }

    this -> LegalMoves = LegalMoves ;

}

class Queen : public Piece {
public :
    Queen(string,int,int) ;
    void GetLegalMoves() ;
};

void Queen::GetLegalMoves() {
    unordered_set < pair < int , int >, pair_hash > LegalMoves = {} ;

    ///to the top right
    for ( int i = this -> positionX + 1, j = this -> positionY + 1; Inside(i,j) ; ++i, ++j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if (Board[i][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][j]->color != Board[this->positionX][this->positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }


    ///to the bottom right
    for ( int i = this -> positionX - 1, j = this -> positionY + 1; Inside(i,j) ; --i, ++j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if (Board[i][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][j]->color != Board[this->positionX][this->positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }

    ///to the top left
    for ( int i = this -> positionX - 1, j = this -> positionY - 1; Inside(i,j) ; --i, --j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if (Board[i][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][j]->color != Board[this->positionX][this->positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }

    ///to the bottom left
    for ( int i = this -> positionX + 1, j = this -> positionY - 1; Inside(i,j) ; ++i, --j ) {
        if ( Board[i][j] == nullptr )
            LegalMoves.insert(make_pair(i,j)) ;
        else {
            if ( Board[i][j]->color == Board[this -> positionX][this -> positionY]->color)
                break ;
            if ( Board[i][j]->color != Board[this -> positionX][this -> positionY]->color && Board[i][j]->color != "") {
                LegalMoves.insert(make_pair(i, j));
                break;
            }
        }
    }

    ///to the right
    for ( int j = this -> positionY + 1 ; Inside(this->positionX,j) ; ++j ) {
        if ( Board[this -> positionX][j] == nullptr )
            LegalMoves.insert(make_pair(this->positionX, j));
        else {
            if (Board[this->positionX][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[this->positionX][j]->color != Board[this->positionX][this->positionY]->color &&
                Board[this->positionX][j]->color != "") {
                LegalMoves.insert(make_pair(this->positionX, j));
                break;
            }
        }

    }

    ///to the left
    for ( int j = this -> positionY - 1 ; Inside(this->positionX,j) ; --j ) {
        if ( Board[this -> positionX][j] == nullptr )
            LegalMoves.insert(make_pair(this->positionX, j));
        else {
            if (Board[this->positionX][j]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[this->positionX][j]->color != Board[this->positionX][this->positionY]->color &&
                Board[this->positionX][j]->color != "") {
                LegalMoves.insert(make_pair(this->positionX, j));
                break;
            }
        }

    }

    ///to the bottom
    for ( int i = this -> positionX + 1; Inside(i,this->positionY) ; ++i ) {
        if ( Board[i][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(i, this -> positionY));
        else {
            if (Board[i][this->positionY]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][this->positionY]->color != Board[this->positionX][this->positionY]->color &&
                Board[i][this->positionY]->color != "") {
                LegalMoves.insert(make_pair(i, this->positionY));
                break;
            }
        }

    }

    ///to the top
    for ( int i = this -> positionX - 1 ; Inside(i,this->positionY) ; --i ) {
        if ( Board[i][this -> positionY] == nullptr )
            LegalMoves.insert(make_pair(i, this -> positionY));
        else {
            if (Board[i][this->positionY]->color == Board[this->positionX][this->positionY]->color)
                break;
            if (Board[i][this->positionY]->color != Board[this->positionX][this->positionY]->color &&
                Board[i][this->positionY]->color != "") {
                LegalMoves.insert(make_pair(i, this->positionY));
                break;
            }
        }
    }

    this -> LegalMoves = LegalMoves ;

}

Queen::Queen(string color, int positionX , int positionY ) {
    this -> name = "Queen" ;
    this -> color = color ;
    this -> positionX = positionX ;
    this -> positionY = positionY ;
}



class King : public Piece {
public :
    King(string,int,int,bool);
    void GetLegalMoves() ;
};

King::King(string color, int positionX , int positionY, bool moved = false) {
    this -> name = "King" ;
    this -> color = color ;
    this -> moved = moved ;
    this -> positionX = positionX ;
    this -> positionY = positionY ;
}



void King::GetLegalMoves() {
    unordered_set < pair < int , int >, pair_hash > LegalMoves = {} ;
    int dx[] = {0,0,-1,-1,-1,1,1,1} ;
    int dy[] = {1,-1,0,1,-1,0,1,-1} ;
    if ( color == "White") {
        for (auto CurrBlackPiece : BlackPieces) {
            CurrBlackPiece ->GetLegalMoves();
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for (it = (CurrBlackPiece -> LegalMoves).begin(); it != (CurrBlackPiece -> LegalMoves).end(); ++it)
                LegalMoves.insert(make_pair(it->first, it->second));

        }
    }
    if ( color == "Black") {
        for (auto CurrWhitePiece : WhitePieces) {
            CurrWhitePiece->GetLegalMoves();
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for (it = (CurrWhitePiece->LegalMoves).begin(); it != (CurrWhitePiece->LegalMoves).end(); ++it)
                LegalMoves.insert(make_pair(it->first, it->second));
        }
    }
    unordered_set < pair < int , int >, pair_hash > LegalMovesKing = {} ;
    for (int i = 0 ; i < 8 ; ++i )
        if (Inside(this -> positionX + dx[i],this -> positionY + dy[i])) {
            auto pos = LegalMoves.find(make_pair(this -> positionX + dx[i],this -> positionY + dy[i])) ;
            if ( pos == LegalMoves.end() ) {
                if (Board[this->positionX + dx[i]][this->positionY + dy[i]] == nullptr)
                    LegalMovesKing.insert(make_pair(this->positionX + dx[i], this->positionY + dy[i]));
                else if (Board[this->positionX + dx[i]][this->positionY + dy[i]]->color !=
                         Board[this->positionX][this->positionY]->color)
                    LegalMovesKing.insert(make_pair(this->positionX + dx[i], this->positionY + dy[i]));
            }
        }


    this -> LegalMoves = LegalMovesKing ;

}


bool Check ( string color ) {

    if ( color == "White" ) {
        pair <int, int> aux = GetKingPosition("White");
        int dx = aux.first;
        int dy = aux.second;
        for (auto CurrBlackPiece : BlackPieces) {
            CurrBlackPiece -> GetLegalMoves() ;
            if (CurrBlackPiece -> LegalMoves.find({dx, dy}) != CurrBlackPiece -> LegalMoves.end())
                return true;
        }
    }
    if ( color == "Black" ) {
        pair <int, int> aux = GetKingPosition("Black");
        int dx = aux.first;
        int dy = aux.second;
        for ( auto CurrWhitePiece : WhitePieces) {
                CurrWhitePiece -> GetLegalMoves() ;
                if (CurrWhitePiece -> LegalMoves.find({dx, dy}) != CurrWhitePiece -> LegalMoves.end())
                    return true;
        }
    }
    return false ;
}

pair <int, int> GetKingPosition (string color)
{
    if (color == "White")
    {
        for (auto CurrWhitePiece : WhitePieces)
            if (CurrWhitePiece -> name == "King")
                return {CurrWhitePiece -> positionX, CurrWhitePiece -> positionY};
    }
    else
    {
        for (auto CurrBlackPiece : BlackPieces)
            if (CurrBlackPiece -> name == "King")
                return {CurrBlackPiece -> positionX, CurrBlackPiece -> positionY};

    }
    return {0, 0};
}


void CreateBoard() {
    for ( int j = 1 ; j <= 8 ; ++j ) {
        WhitePieces.insert(Board[2][j] = new Pawn("White",2,j)) ;
        BlackPieces.insert(Board[7][j] = new Pawn("Black",7,j));
    }
    WhitePieces.insert(Board[1][1] = new Rook("White",1,1) );
    WhitePieces.insert(Board[1][8] = new Rook("White",1,8) );
    BlackPieces.insert(Board[8][1] = new Rook ("Black",8,1) ) ;
    BlackPieces.insert(Board[8][8] = new Rook("Black",8,8) );
    WhitePieces.insert(Board[1][2] = new Knight("White",1,2) );
    WhitePieces.insert(Board[1][7] = new Knight("White",1,7) ) ;
    BlackPieces.insert(Board[8][2] = new Knight("Black",8,2) );
    BlackPieces.insert(Board[8][7] = new Knight("Black",8,7) );
    WhitePieces.insert(Board[1][3] = new Bishop("White",1,3) );
    WhitePieces.insert(Board[1][6] = new Bishop("White",1,6) );
    BlackPieces.insert(Board[8][3] = new Bishop("Black",8,3) ) ;
    BlackPieces.insert(Board[8][6] = new Bishop("Black",8,6) );
    WhitePieces.insert(Board[1][4] = new King("White",1,4) );
    BlackPieces.insert(Board[8][4] = new King("Black",8,4) ) ;
    WhitePieces.insert(Board[1][5] = new Queen("White",1,5) );
    BlackPieces.insert(Board[8][5] = new Queen("Black",8,5) );
    for ( int i = 3 ; i <= 6 ; ++i )
        for ( int j = 1 ; j <= 8 ; ++j )
            Board[i][j] = new Piece() ;

}




int Evaluate() {

    /// Material and positional advantage
    int Targets[9][9] = {0};
    int WhiteMaterial = 0 , BlackMaterial = 0 ;
    int PositionFactorWhite = 0, PoistionFactorBlack = 0 ;
    int MatricealPositionWhite = 0 , MatricealPositionBlack = 0 ;
    for (auto i : WhitePieces) {
        if ( typeid(*i) == typeid(Pawn)) {
            WhiteMaterial = WhiteMaterial + 1;
            i->GetLegalMoves();
            PositionFactorWhite = PositionFactorWhite + 1 * (i->LegalMoves).size();
            MatricealPositionWhite += WhitePawnMatrix[i -> positionX][i -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (i->LegalMoves).begin() ; it != (i->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] + 1;
        }
        if ( typeid(*i) == typeid(Knight)) {
            WhiteMaterial = WhiteMaterial + 3;
            i->GetLegalMoves();
            PositionFactorWhite = PositionFactorWhite + i->LegalMoves.size();
            MatricealPositionWhite += WhiteKnightMatrix[i -> positionX][i -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (i->LegalMoves).begin() ; it != (i->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] + 1;
        }
        if ( typeid(*i) == typeid(Bishop)) {
            WhiteMaterial = WhiteMaterial + 3;
            i->GetLegalMoves();
            PositionFactorWhite = PositionFactorWhite + i->LegalMoves.size();
            MatricealPositionWhite += WhiteBishopMatrix[i -> positionX][i -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (i->LegalMoves).begin() ; it != (i->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] + 1;
        }
        if ( typeid(*i) == typeid(Rook)) {
            WhiteMaterial = WhiteMaterial + 5;
            i->GetLegalMoves();
            PositionFactorWhite = PositionFactorWhite + i->LegalMoves.size();
            MatricealPositionWhite += WhiteRookMatrix[i -> positionX][i -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (i->LegalMoves).begin() ; it != (i->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] + 1;
        }
        if ( typeid(*i) == typeid(Queen)) {
            WhiteMaterial = WhiteMaterial + 9;
            i->GetLegalMoves();
            PositionFactorWhite = PositionFactorWhite + i->LegalMoves.size();
            MatricealPositionWhite += WhiteQueenMatrix[i -> positionX][i -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (i->LegalMoves).begin() ; it != (i->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] + 1;
        }
    }
    for (auto CurrBlackPiece : BlackPieces) {
        if ( typeid(*CurrBlackPiece) == typeid(Pawn)) {
            BlackMaterial = BlackMaterial + 1;
            CurrBlackPiece->GetLegalMoves();
            PoistionFactorBlack = PoistionFactorBlack + CurrBlackPiece->LegalMoves.size();
            MatricealPositionBlack += BlackQueenMatrix[CurrBlackPiece -> positionX][CurrBlackPiece -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (CurrBlackPiece->LegalMoves).begin() ; it != (CurrBlackPiece->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] - 1;
        }
        if ( typeid(*CurrBlackPiece) == typeid(Knight)) {
            BlackMaterial = BlackMaterial + 3;
            CurrBlackPiece->GetLegalMoves();
            PoistionFactorBlack = PoistionFactorBlack + CurrBlackPiece->LegalMoves.size();
            MatricealPositionBlack += BlackQueenMatrix[CurrBlackPiece -> positionX][CurrBlackPiece -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (CurrBlackPiece->LegalMoves).begin() ; it != (CurrBlackPiece->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] - 1;
        }
        if ( typeid(*CurrBlackPiece) == typeid(Bishop)) {
            BlackMaterial = BlackMaterial + 3;
            CurrBlackPiece->GetLegalMoves();
            PoistionFactorBlack = PoistionFactorBlack + CurrBlackPiece->LegalMoves.size();
            MatricealPositionBlack += BlackQueenMatrix[CurrBlackPiece -> positionX][CurrBlackPiece -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (CurrBlackPiece->LegalMoves).begin() ; it != (CurrBlackPiece->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] - 1;
        }
        if ( typeid(*CurrBlackPiece) == typeid(Rook)) {
            BlackMaterial = BlackMaterial + 5;
            CurrBlackPiece->GetLegalMoves();
            PoistionFactorBlack = PoistionFactorBlack + CurrBlackPiece->LegalMoves.size();
            MatricealPositionBlack += BlackQueenMatrix[CurrBlackPiece -> positionX][CurrBlackPiece -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (CurrBlackPiece->LegalMoves).begin() ; it != (CurrBlackPiece->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] - 1;
        }
        if ( typeid(*CurrBlackPiece) == typeid(Queen)) {
            BlackMaterial = BlackMaterial + 9;
            CurrBlackPiece->GetLegalMoves();
            PoistionFactorBlack = PoistionFactorBlack + CurrBlackPiece->LegalMoves.size();
            MatricealPositionBlack += BlackQueenMatrix[CurrBlackPiece -> positionX][CurrBlackPiece -> positionY] ;
            ///set < pair < int , int > > :: iterator it ;
            unordered_set < pair < int , int >, pair_hash > :: iterator it ;
            for ( it = (CurrBlackPiece->LegalMoves).begin() ; it != (CurrBlackPiece->LegalMoves).end(); ++it )
                Targets[it -> first][it -> second] = Targets[it -> first][it -> second] - 1;
        }
    }

    ///When a square is attacked by more pieces
    for ( int i = 1 ; i <= 8 ; ++i ) {
        for (int j = 1; j <= 8; ++j ) {
            if ( Targets[i][j] > 0 && Board[i][j] != nullptr ) {
                if ( Board[i][j] -> color == "Black" ) {
                    if (typeid(*Board[i][j]) == typeid(Pawn) )
                        BlackMaterial = BlackMaterial - 1 ;
                    if (typeid(*Board[i][j]) == typeid(Knight) )
                        BlackMaterial = BlackMaterial - 3 ;
                    if (typeid(*Board[i][j]) == typeid(Bishop) )
                        BlackMaterial = BlackMaterial - 3 ;
                    if (typeid(*Board[i][j]) == typeid(Rook) )
                        BlackMaterial = BlackMaterial - 5 ;
                    if (typeid(*Board[i][j]) == typeid(Queen) )
                        BlackMaterial = BlackMaterial - 9 ;
                }
            }
            if ( Targets[i][j] < 0 && Board[i][j] != nullptr ) {
                if (Board[i][j]->color == "White") {
                    if (typeid(*Board[i][j]) == typeid(Pawn))
                        WhiteMaterial = WhiteMaterial - 1;
                    if (typeid(*Board[i][j]) == typeid(Knight))
                        WhiteMaterial = WhiteMaterial - 3;
                    if (typeid(*Board[i][j]) == typeid(Bishop))
                        WhiteMaterial = WhiteMaterial - 3;
                    if (typeid(*Board[i][j]) == typeid(Rook))
                        WhiteMaterial = WhiteMaterial - 5;
                    if (typeid(*Board[i][j]) == typeid(Queen))
                        WhiteMaterial = WhiteMaterial - 9;
                }
            }
        }

    }
    ///King Safety
    int dxWhite, dyWhite, dxBlack, dyBlack ;
    float KingSafetyWhite = 0 ;
    float KingSafetyBlack = 0 ;
    int dx[] = {0,0,-1,-1,-1,1,1,1} ;
    int dy[] = {1,-1,0,1,-1,0,1,-1} ;
    for ( auto CurrWhitePiece : WhitePieces) {
        if ( typeid(*CurrWhitePiece) == typeid(King) ) {
            dxWhite = CurrWhitePiece -> positionX ;
            dyWhite = CurrWhitePiece -> positionY ;
        }
    }
    for ( auto CurrBlackPiece : BlackPieces) {
        if ( typeid(*CurrBlackPiece) == typeid(King) ) {
            dxBlack = CurrBlackPiece -> positionX ;
            dyBlack = CurrBlackPiece -> positionY ;
        }
    }
    for ( int i = 0 ; i < 8 ; ++i ) {
        if (Targets[dxWhite + dx[i]][dyWhite + dy[i]] < 0)
            KingSafetyWhite = KingSafetyWhite - 10;
        if (Targets[dxWhite + dx[i]][dyWhite + dy[i]] == 0)
            KingSafetyWhite = KingSafetyWhite - 3;
        if (Targets[dxWhite + dx[i]][dyWhite + dy[i]] > 0)
            KingSafetyWhite = KingSafetyWhite + 1;
        if (Targets[dxBlack + dx[i]][dyBlack + dy[i]] > 0)
            KingSafetyBlack = KingSafetyBlack - 10;
        if (Targets[dxBlack + dx[i]][dyBlack + dy[i]] == 0)
            KingSafetyBlack = KingSafetyBlack - 3;
        if (Targets[dxBlack + dx[i]][dyBlack + dy[i]] < 0)
            KingSafetyBlack = KingSafetyBlack + 1;
    }


    float WhiteFactor = WhiteMaterial * 10 + PositionFactorWhite + MatricealPositionWhite + KingSafetyWhite  ;
    float BlackFactor = BlackMaterial * 10 + PoistionFactorBlack + MatricealPositionBlack + KingSafetyBlack  ;
    return WhiteFactor - BlackFactor ;

}


int NextMove (string color, int depth, int alpha, int beta, bool maximazingPlayer) {
    if ( depth == 0 )
        return Evaluate() ;

    set < pair < pair < int , int > , pair < int , int > > > WhiteLegalMoves = {};
    set < pair < pair < int , int > , pair < int , int > > > BlackLegalMoves = {};
    pair < pair < int , int > , pair < int , int > > bestMove ;
    if ( maximazingPlayer == false ) {
        set<pair<pair<int, int>, pair<int, int> > > LegalMoves = {};
        for (auto CurrBlackPiece : BlackPieces ) {
            if (typeid(*CurrBlackPiece) == typeid(Pawn)) {
                CurrBlackPiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrBlackPiece->LegalMoves).begin(); it != (CurrBlackPiece->LegalMoves).end(); ++it)
                    BlackLegalMoves.insert(make_pair(make_pair(CurrBlackPiece->positionX, CurrBlackPiece->positionY),
                                                     make_pair(it->first, it->second)));
            }
            if (typeid(*CurrBlackPiece) == typeid(Knight)) {
                CurrBlackPiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrBlackPiece->LegalMoves).begin(); it != (CurrBlackPiece->LegalMoves).end(); ++it)
                    BlackLegalMoves.insert(make_pair(make_pair(CurrBlackPiece->positionX, CurrBlackPiece->positionY),
                                                     make_pair(it->first, it->second)));
            }
            if (typeid(*CurrBlackPiece) == typeid(Bishop)) {
                CurrBlackPiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrBlackPiece->LegalMoves).begin(); it != (CurrBlackPiece->LegalMoves).end(); ++it)
                    BlackLegalMoves.insert(make_pair(make_pair(CurrBlackPiece->positionX, CurrBlackPiece->positionY),
                                                     make_pair(it->first, it->second)));
            }
            if (typeid(*CurrBlackPiece) == typeid(Rook)) {
                CurrBlackPiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrBlackPiece->LegalMoves).begin(); it != (CurrBlackPiece->LegalMoves).end(); ++it)
                    BlackLegalMoves.insert(make_pair(make_pair(CurrBlackPiece->positionX, CurrBlackPiece->positionY),
                                                     make_pair(it->first, it->second)));
            }
            if (typeid(*CurrBlackPiece) == typeid(Queen)) {
                CurrBlackPiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrBlackPiece->LegalMoves).begin(); it != (CurrBlackPiece->LegalMoves).end(); ++it)
                    BlackLegalMoves.insert(make_pair(make_pair(CurrBlackPiece->positionX, CurrBlackPiece->positionY),
                                                     make_pair(it->first, it->second)));
            }
        }
    }
    if (maximazingPlayer == true) {
        set<pair<pair<int, int>, pair<int, int> > > LegalMoves = {};
        for (auto CurrWhitePiece : WhitePieces) {
            if (typeid(*CurrWhitePiece) == typeid(Pawn)) {
                CurrWhitePiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrWhitePiece->LegalMoves).begin(); it != (CurrWhitePiece->LegalMoves).end(); ++it)
                    WhiteLegalMoves.insert(make_pair(make_pair(CurrWhitePiece->positionX, CurrWhitePiece->positionY),
                                                make_pair(it->first, it->second)));
            }
            if (typeid(*CurrWhitePiece) == typeid(Knight)) {
                CurrWhitePiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrWhitePiece->LegalMoves).begin(); it != (CurrWhitePiece->LegalMoves).end(); ++it)
                    WhiteLegalMoves.insert(make_pair(make_pair(CurrWhitePiece->positionX, CurrWhitePiece->positionY),
                                                make_pair(it->first, it->second)));
            }
            if (typeid(*CurrWhitePiece) == typeid(Bishop)) {
                CurrWhitePiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrWhitePiece->LegalMoves).begin(); it != (CurrWhitePiece->LegalMoves).end(); ++it)
                    WhiteLegalMoves.insert(make_pair(make_pair(CurrWhitePiece->positionX, CurrWhitePiece->positionY),
                                                make_pair(it->first, it->second)));
            }
            if (typeid(*CurrWhitePiece) == typeid(Rook)) {
                CurrWhitePiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrWhitePiece->LegalMoves).begin(); it != (CurrWhitePiece->LegalMoves).end(); ++it)
                    WhiteLegalMoves.insert(make_pair(make_pair(CurrWhitePiece->positionX, CurrWhitePiece->positionY),
                                                make_pair(it->first, it->second)));
            }
            if (typeid(*CurrWhitePiece) == typeid(Queen)) {
                CurrWhitePiece->GetLegalMoves();
                unordered_set<pair<int, int>, pair_hash >::iterator it;
                for (it = (CurrWhitePiece->LegalMoves).begin(); it != (CurrWhitePiece->LegalMoves).end(); ++it)
                    WhiteLegalMoves.insert(make_pair(make_pair(CurrWhitePiece->positionX, CurrWhitePiece->positionY),
                                                make_pair(it->first, it->second)));
            }
        }
    }
    if ( maximazingPlayer == false ) {
        int maxEvaluation = -99999 ;
        set < pair < pair < int , int > , pair < int , int > > > :: iterator it ;
        for ( it = BlackLegalMoves.begin() ; it != BlackLegalMoves.end() ; ++it ) {
            int startx = (it -> first).first ;
            int starty = (it -> first).second ;
            int stopx = (it -> second).first ;
            int stopy = (it -> second).second;
            ///Make a move
            Piece *save1 = Board[startx][starty], *save2 = nullptr, *NewPiece = nullptr;
            NewPiece = save1;
            NewPiece -> positionX = stopx;
            NewPiece -> positionY = stopy;
            if (Board[stopx][stopy] == nullptr)
                Board[stopx][stopy] = new Piece;
            else save2 = Board[stopx][stopy];
            BlackPieces.erase(Board[startx][starty] );
            BlackPieces.insert(NewPiece);
            Board[stopx][stopy] = Board[startx][starty] ;
            Board[startx][starty] = nullptr ;
            if (save2 != nullptr && WhitePieces.find(save2) != WhitePieces.end())
                    WhitePieces.erase(save2);
            ///Evaluate
            int currentEvaluation = NextMove(color,depth - 1, alpha, beta,false) ;
            ///Undo the move
            Board[startx][starty] = save1;
            Board[stopx][stopy] = save2;
            BlackPieces.insert(save1);
            BlackPieces.erase(NewPiece);
            if (save2 != nullptr)
                WhitePieces.insert(save2);
            if ( currentEvaluation > maxEvaluation ) {
                maxEvaluation = currentEvaluation ;
                bestMove = make_pair(make_pair(startx,starty),make_pair(stopx,stopy)) ;
            }
            ///alpha beta prunning
            alpha = maximum <int> (alpha,currentEvaluation) ;
            if ( beta <= alpha )
                break ;
        }
    }
    else {
        int minEvaluation = 99999 ;
        set < pair < pair < int , int > , pair < int , int > > > :: iterator it ;
        for ( it = WhiteLegalMoves.begin() ; it != WhiteLegalMoves.end() ; ++it ) {
            int startx = (it -> first).first ;
            int starty = (it -> first).second ;
            int stopx = (it -> second).first ;
            int stopy = (it -> second).second;
            ///Make a move
            Piece *save1 = Board[startx][starty], *save2 = nullptr, *NewPiece = nullptr;
            NewPiece = save1;
            NewPiece -> positionX = stopx;
            NewPiece -> positionY = stopy;
            if (Board[stopx][stopy] == nullptr)
                Board[stopx][stopy] = new Piece;
            else save2 = Board[stopx][stopy];
            WhitePieces.erase(Board[startx][starty] );
            WhitePieces.insert(NewPiece);
            Board[stopx][stopy] = Board[startx][starty] ;
            Board[startx][starty] = nullptr ;
            if (save2 != nullptr && BlackPieces.find(save2) != BlackPieces.end())
                    BlackPieces.erase(save2);
            ///Evaluate
            int currentEvaluation = NextMove(color,depth - 1, alpha, beta,false) ;
            ///Undo the move
            Board[startx][starty] = save1;
            Board[stopx][stopy] = save2;
            WhitePieces.insert(save1);
            WhitePieces.erase(NewPiece);
            if (save2 != nullptr)
                BlackPieces.insert(save2);

            if ( currentEvaluation < minEvaluation ) {
                minEvaluation = currentEvaluation ;
                bestMove = make_pair(make_pair(startx,starty),make_pair(stopx,stopy)) ;
            }
            beta = minimum <int> (beta,currentEvaluation) ;
            if ( beta <= alpha )
                break ;
        }
    }

}

pair < int , int > Solve(int depth, string color) {
    pair < int , int >  bestMove ;

}

void CreateBoard1() {
    BlackPieces.insert(Board[8][1] = new King("Black",8,1) );
    BlackPieces.insert(Board[7][1] = new Rook("Black",7,1) );
    BlackPieces.insert(Board[1][3] = new Bishop("Black",1,3) );
    BlackPieces.insert(Board[5][7] = new Rook("Black",5,7) );
    BlackPieces.insert(Board[5][6] = new Rook("Black",5,6) );
    BlackPieces.insert(Board[6][6] = new Rook("Black",6,6) );
    ////////////////////////////////////////////////////////////
    WhitePieces.insert(Board[1][1] = new Rook("White",1,1) );
    WhitePieces.insert(Board[1][4] = new Rook("White",1,4) );
    WhitePieces.insert(Board[3][2] = new Bishop("White",3,2) );
    WhitePieces.insert(Board[3][3] = new Bishop("White",3,3) );
    WhitePieces.insert(Board[3][7] = new Knight("White",3,7) );
    WhitePieces.insert(Board[2][5] = new King("White",2,5) );
    WhitePieces.insert(Board[4][1] = new Pawn("White",4,1) );
    WhitePieces.insert(Board[5][2] = new Pawn("White",5,2) );
    WhitePieces.insert(Board[2][7] = new Pawn("White",2,7) );
    WhitePieces.insert(Board[2][8] = new Pawn("White",2,8) );


}


int main() {
    CreateBoard1() ;
    cout << Evaluate() << " " ;
    cout << NextMove("White",1,9999,-9999,true) ;
}

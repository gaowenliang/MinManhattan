#ifndef MANHATTAN_H
#define MANHATTAN_H

#include <ceres/ceres.h>
#include <cmath>
#include <eigen3/Eigen/Eigen>

class MinManhattan
{
    class ManhattanError
    {
        public:
        ManhattanError( const double& _x, const double& _y )
        : x( _x )
        , y( _y )
        {
        }

        template< typename T >
        T ManhattanDistance( T _x, T _y, T _x2, T _y2 ) const
        {
            return sqrt( ( _x - _x2 ) * ( _x - _x2 ) ) + sqrt( ( _y - _y2 ) * ( _y - _y2 ) );
        }

        template< typename T >
        bool operator( )( const T* const _paramt, T* residuals ) const
        {
            T _x = T( _paramt[0] );
            T _y = T( _paramt[1] );

            residuals[0] = ManhattanDistance( _x, _y, T( x ), T( y ) );

            return true;
        }

        double x;
        double y;
    };

    public:
    MinManhattan( std::vector< Eigen::Vector2d > pts );
    double ManhattanDistance( Eigen::Vector2d pt, Eigen::Vector2d pt2 ) const;
    Eigen::Vector2d initWithAvg( std::vector< Eigen::Vector2d > pts );
    void print( const std::vector< Eigen::Vector2d > pts, const Eigen::Vector2d pt_init, const Eigen::Vector2d pt_final );
    Eigen::Vector2d getFinalPoint( );

    double des_x;
    double des_y;
};

#endif // MANHATTAN_H

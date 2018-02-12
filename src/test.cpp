#include "lib/manhattan.h"
#include <ceres/ceres.h>
#include <eigen3/Eigen/Eigen>

int
main( int argc, char** argv )
{
    std::vector< Eigen::Vector2d > pts;
    pts.push_back( Eigen::Vector2d( 0, 0 ) );
    pts.push_back( Eigen::Vector2d( 0, 5 ) );
    pts.push_back( Eigen::Vector2d( 0, 10 ) );
    pts.push_back( Eigen::Vector2d( 0, 15 ) );
    pts.push_back( Eigen::Vector2d( 0, 20 ) );
    pts.push_back( Eigen::Vector2d( 10, 0 ) );
    pts.push_back( Eigen::Vector2d( 20, 0 ) );
    pts.push_back( Eigen::Vector2d( 10, 10 ) );
    pts.push_back( Eigen::Vector2d( 150, 0 ) );

    MinManhattan man( pts );
    std::cout << "Final point is: " << man.getFinalPoint( ).transpose( ) << std::endl;

    return 0;
}

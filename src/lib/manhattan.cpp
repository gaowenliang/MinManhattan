#include "manhattan.h"

MinManhattan::MinManhattan( std::vector< Eigen::Vector2d > pts )
{
    Eigen::Vector2d pt_init = initWithAvg( pts );
    std::cout << "Init point: " << pt_init.transpose( ) << std::endl;

    double param[] = { pt_init( 0 ), pt_init( 1 ) };

    ceres::Problem problem;
    for ( int i = 0; i < pts.size( ); ++i )
    {
        ceres::CostFunction* f = new ceres::AutoDiffCostFunction< ManhattanError, 1, 2 >(
        new ManhattanError( pts[i].x( ), pts[i].y( ) ) );

        problem.AddResidualBlock( f, NULL /* squared loss */, param );
    }
    ceres::Solver::Options options;
    options.minimizer_progress_to_stdout = true;
    //        options.logging_type                 = ceres::SILENT;
    options.trust_region_strategy_type = ceres::DOGLEG;

    ceres::Solver::Summary summary;
    ceres::Solve( options, &problem, &summary );

    des_x = param[0];
    des_y = param[1];

    Eigen::Vector2d pt_final( des_x, des_y );
    print( pts, pt_init, pt_final );
}

void
MinManhattan::print( const std::vector< Eigen::Vector2d > pts, const Eigen::Vector2d pt_init, const Eigen::Vector2d pt_final )
{
    double sum_init  = 0.0;
    double sum_final = 0.0;

    std::cout << "points    |  init distance | final distance" << std::endl;
    for ( auto& pt : pts )
    {
        sum_init += ManhattanDistance( pt, pt_init );
        sum_final += ManhattanDistance( pt, pt_final );

        std::cout << "  " << pt.transpose( )                    //
                  << " | " << ManhattanDistance( pt, pt_init )  //
                  << " | " << ManhattanDistance( pt, pt_final ) //
                  << std::endl;
    }
    std::cout << "Init point is: " << pt_init.transpose( ) << std::endl;
    std::cout << "Init Manhattan Distance is: " << sum_init << std::endl;
    std::cout << "Final point is: " << pt_final.transpose( ) << std::endl;
    std::cout << "Final Manhattan Distance is: " << sum_final << std::endl;
}

Eigen::Vector2d
MinManhattan::getFinalPoint( )
{
    return Eigen::Vector2d( des_x, des_y );
}

double
MinManhattan::ManhattanDistance( Eigen::Vector2d pt, Eigen::Vector2d pt2 ) const
{
    return sqrt( ( pt.x( ) - pt2.x( ) ) * ( pt.x( ) - pt2.x( ) ) )
           + sqrt( ( pt.y( ) - pt2.y( ) ) * ( pt.y( ) - pt2.y( ) ) );
}

Eigen::Vector2d
MinManhattan::initWithAvg( std::vector< Eigen::Vector2d > pts )
{
    Eigen::Vector2d init_pt;
    init_pt.setZero( );

    for ( auto& pt : pts )
        init_pt += pt;
    init_pt = init_pt / pts.size( );

    return init_pt;
}

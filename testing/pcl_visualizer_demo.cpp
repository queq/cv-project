#include <iostream>

#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>

typedef pcl::PointXYZRGBA PointType;

bool setup = true;
pcl::PointCloud<PointType>::Ptr point_cloud_ptr(new pcl::PointCloud<PointType>);

void grabberCallback(const pcl::PointCloud<PointType>::ConstPtr &cloud)
{
  pcl::copyPointCloud(*cloud, *point_cloud_ptr);
}

boost::shared_ptr<pcl::visualization::PCLVisualizer> rgbViewer (pcl::PointCloud<PointType>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<PointType> rgb(cloud);
  viewer->addPointCloud<PointType> (cloud, rgb, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}

// --------------
// -----Main-----
// --------------
int main (int argc, char** argv)
{
  // ------------------------------------
  // -----Create example point cloud-----
  // ------------------------------------

  pcl::Grabber* grabber = new pcl::OpenNIGrabber();
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

  boost::function<void (const pcl::PointCloud<PointType>::ConstPtr&)> f = boost::bind (&grabberCallback, _1);

  grabber->registerCallback(f);

  grabber->start();

  viewer = rgbViewer(point_cloud_ptr);

  //--------------------
  // -----Main loop-----
  //--------------------
  while (!viewer->wasStopped())
  {
    pcl::visualization::PointCloudColorHandlerRGBField<PointType> rgb(point_cloud_ptr);
    viewer->updatePointCloud<PointType> (point_cloud_ptr, rgb, "sample cloud");
    viewer->spinOnce(100);
    boost::this_thread::sleep(boost::posix_time::microseconds (100000));
  }

  grabber->stop();
  return 0;
}

/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* Author: Ioan Sucan */

#ifndef MOVEIT_VISUALIZATION_SCENE_DISPLAY_RVIZ_PLUGIN_PLANNING_SCENE_RENDER_
#define MOVEIT_VISUALIZATION_SCENE_DISPLAY_RVIZ_PLUGIN_PLANNING_SCENE_RENDER_

#include <moveit/planning_scene/planning_scene.h>
#include <moveit/rviz_plugin_render_tools/render_shapes.h>
#include <rviz/helpers/color.h>
#include <OGRE/OgreMaterial.h>

namespace Ogre
{
class SceneNode;
}

namespace rviz
{
class DisplayContext;
}

namespace moveit_rviz_plugin
{

class RobotStateVisualization;
typedef boost::shared_ptr<RobotStateVisualization> RobotStateVisualizationPtr;

class RenderShapes;
typedef boost::shared_ptr<RenderShapes> RenderShapesPtr;

class PlanningSceneRender
{
public:
  PlanningSceneRender(Ogre::SceneNode *root_node, rviz::DisplayContext *context,
                      const RobotStateVisualizationPtr &robot);
  ~PlanningSceneRender();

  Ogre::SceneNode* getGeometryNode()
  {
    return planning_scene_geometry_node_;
  }

  const RobotStateVisualizationPtr& getRobotVisualization()
  {
    return scene_robot_;
  }

  void renderPlanningScene(const planning_scene::PlanningSceneConstPtr &scene,
                           const rviz::Color &default_scene_color,
                           const rviz::Color &default_attached_color,
                           OctreeVoxelRenderMode voxel_render_mode,
                           OctreeVoxelColorMode voxel_color_mode,
                           float default_scene_alpha);
  void clear();

private:

  Ogre::SceneNode *planning_scene_geometry_node_;
  rviz::DisplayContext *context_;
  RenderShapesPtr render_shapes_;
  RobotStateVisualizationPtr scene_robot_;

};

typedef boost::shared_ptr<PlanningSceneRender> PlanningSceneRenderPtr;
typedef boost::shared_ptr<const PlanningSceneRender> PlanningSceneRenderConstPtr;

}

#endif

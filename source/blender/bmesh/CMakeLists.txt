# ***** BEGIN GPL LICENSE BLOCK *****
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# The Original Code is Copyright (C) 2006, Blender Foundation
# All rights reserved.
#
# The Original Code is: all of this file.
#
# Contributor(s): Jacques Beaurain.
#
# ***** END GPL LICENSE BLOCK *****

set(INC 
	.
	../blenfont
	../blenkernel
	../blenlib
	../makesdna
	../../../intern/guardedalloc
	../../../extern/rangetree
	../../../intern/opennl/extern
)

set(INC_SYS

)

set(SRC
	operators/bmo_bevel.c
	operators/bmo_connect.c
	operators/bmo_slide.c
	operators/bmo_create.c
	operators/bmo_dissolve.c
	operators/bmo_dupe.c
	operators/bmo_edgesplit.c
	operators/bmo_extrude.c
	operators/bmo_hull.c
	operators/bmo_inset.c
	operators/bmo_join_triangles.c
	operators/bmo_mesh_conv.c
	operators/bmo_mirror.c
	operators/bmo_primitive.c
	operators/bmo_removedoubles.c
	operators/bmo_similar.c
	operators/bmo_smooth_laplacian.c
	operators/bmo_symmetrize.c
	operators/bmo_subdivide.c
	operators/bmo_subdivide.h
	operators/bmo_triangulate.c
	operators/bmo_unsubdivide.c
	operators/bmo_utils.c
	operators/bmo_wireframe.c

	intern/bmesh_construct.c
	intern/bmesh_construct.h
	intern/bmesh_core.c
	intern/bmesh_core.h
	intern/bmesh_inline.h
	intern/bmesh_interp.c
	intern/bmesh_interp.h
	intern/bmesh_iterators.c
	intern/bmesh_iterators.h
	intern/bmesh_iterators_inline.h
	intern/bmesh_log.c
	intern/bmesh_log.h
	intern/bmesh_marking.c
	intern/bmesh_marking.h
	intern/bmesh_mesh.c
	intern/bmesh_mesh.h
	intern/bmesh_mesh_conv.c
	intern/bmesh_mesh_conv.h
	intern/bmesh_mesh_validate.c
	intern/bmesh_mesh_validate.h
	intern/bmesh_mods.c
	intern/bmesh_mods.h
	intern/bmesh_opdefines.c
	intern/bmesh_operator_api_inline.h
	intern/bmesh_operators.c
	intern/bmesh_operators.h
	intern/bmesh_operators_private.h
	intern/bmesh_polygon.c
	intern/bmesh_polygon.h
	intern/bmesh_private.h
	intern/bmesh_queries.c
	intern/bmesh_queries.h
	intern/bmesh_structure.c
	intern/bmesh_structure.h
	intern/bmesh_walkers.c
	intern/bmesh_walkers.h
	intern/bmesh_walkers_impl.c
	intern/bmesh_walkers_private.h

	intern/bmesh_operator_api.h
	intern/bmesh_error.h

	tools/BME_bevel.c
	tools/bmesh_bevel.c
	tools/bmesh_bevel.h
	tools/bmesh_decimate_collapse.c
	tools/bmesh_decimate_dissolve.c
	tools/bmesh_decimate_unsubdivide.c
	tools/bmesh_decimate.h
	tools/bmesh_edgesplit.c
	tools/bmesh_edgesplit.h

	bmesh.h
	bmesh_class.h
)

if(MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /WX")
endif()

if(WITH_BULLET)
	add_definitions(-DWITH_BULLET)
	list(APPEND INC_SYS
		${BULLET_INCLUDE_DIRS}
	)
endif()

if(WITH_INTERNATIONAL)
	add_definitions(-DWITH_INTERNATIONAL)
endif()

blender_add_lib(bf_bmesh "${SRC}" "${INC}" "${INC_SYS}")

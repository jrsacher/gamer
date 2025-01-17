// This file is part of the GAMer software.
// Copyright (C) 2016-2021
// by Christopher T. Lee and contributors
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, see <http://www.gnu.org/licenses/>
// or write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
// Boston, MA 02111-1307 USA

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "gamer/SurfaceMesh.h"

/// Namespace for all things gamer
namespace gamer
{

namespace py = pybind11;

void init_SMGlobal(py::module& mod){
    py::class_<SMGlobal> global(mod, "Global",
        R"delim(
            Wrapper around a :cpp:class:`gamer::SMGlobal`.
        )delim"
    );

    global.def_readwrite("marker", &SMGlobal::marker, "Domain marker to use when tetrahedralizing.");
    global.def_readwrite("volumeConstraint", &SMGlobal::volumeConstraint, "Domain volumeConstraint to use when tetrahedralizing.");
    global.def_readwrite("useVolumeConstraint", &SMGlobal::useVolumeConstraint, "Use a volume constraint when tetrahedralizing.");
    global.def_readwrite("ishole", &SMGlobal::ishole, "Does this domain represent a hole or not?");
}

} // end namespace gamer

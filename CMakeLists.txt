########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.6)
project(grcompat)

########################################################################
# Setup the python interpreter:
# This allows the user to specify a specific interpreter,
# or finds the interpreter via the built-in cmake module.
########################################################################
#this allows the user to override PYTHON_EXECUTABLE
if(PYTHON_EXECUTABLE)

    set(PYTHONINTERP_FOUND TRUE)

#otherwise if not set, try to automatically find it
else(PYTHON_EXECUTABLE)

    #use the built-in find script
    find_package(PythonInterp)

    #and if that fails use the find program routine
    if(NOT PYTHONINTERP_FOUND)
        find_program(PYTHON_EXECUTABLE NAMES python python2.7 python2.6 python2.5)
        if(PYTHON_EXECUTABLE)
            set(PYTHONINTERP_FOUND TRUE)
        endif(PYTHON_EXECUTABLE)
    endif(NOT PYTHONINTERP_FOUND)

endif(PYTHON_EXECUTABLE)

#make the path to the executable appear in the cmake gui
set(PYTHON_EXECUTABLE ${PYTHON_EXECUTABLE} CACHE FILEPATH "python interpreter")

#make sure we can use -B with python (introduced in 2.6)
if(PYTHON_EXECUTABLE)
    execute_process(
        COMMAND ${PYTHON_EXECUTABLE} -B -c ""
        OUTPUT_QUIET ERROR_QUIET
        RESULT_VARIABLE PYTHON_HAS_DASH_B_RESULT
    )
    if(PYTHON_HAS_DASH_B_RESULT EQUAL 0)
        set(PYTHON_DASH_B "-B")
    endif()
endif(PYTHON_EXECUTABLE)

########################################################################
# Sets the python installation directory GR_PYTHON_DIR
########################################################################
if(NOT DEFINED GR_PYTHON_DIR)
execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "
from distutils import sysconfig
print sysconfig.get_python_lib(plat_specific=True, prefix='')
" OUTPUT_VARIABLE GR_PYTHON_DIR OUTPUT_STRIP_TRAILING_WHITESPACE
)
endif()
file(TO_CMAKE_PATH ${GR_PYTHON_DIR} GR_PYTHON_DIR)

########################################################################
# Install includes
########################################################################
install(DIRECTORY include/grcompat DESTINATION include)

########################################################################
# Install python
########################################################################
install(FILES
    python/gruel/__init__.py
    DESTINATION ${GR_PYTHON_DIR}/gruel
)

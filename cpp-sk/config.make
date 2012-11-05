# add custom variables to this file

# OF_ROOT allows to move projects outside apps/* just set this variable to the
# absoulte path to the OF root folder

#OF_ROOT = ../../../.


# USER_CFLAGS allows to pass custom flags to the compiler
# for example search paths like:
# USER_CFLAGS = -I src/objects

USER_CFLAGS = -I./include \
-I./include/ArmsTracking \
-I./include/Math \
-I./include/Common \
-I./include/SystemUtils \
-I./include/CellsGraph \
-I./include/MedialAxes \
-I./include/Figure \
-I./include/Contours \
-I./include/Tracking \
-I./include/Segmentation \
-I./include/Utils \
-I./include/BodyModel \
-I./include/Converter \
-I./include/Labeling \
-I./include/Settings \
-I./include/Histogram \
-g

# USER_LDFLAGS allows to pass custom flags to the linker
# for example libraries like:
# USER_LD_FLAGS = libs/libawesomelib.a

USER_LDFLAGS =


# use this to add system libraries for example:
# USER_LIBS = -lpango
 
USER_LIBS = -lboost_serialization -lusb-1.0 -lGLEW


# change this to add different compiler optimizations to your project

USER_COMPILER_OPTIMIZATION = -march=native -mtune=native -Os


EXCLUDE_FROM_SOURCE="bin,.xcodeproj,obj,evaluation_tool"

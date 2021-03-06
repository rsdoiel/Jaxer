# Copyright (C) 2006 MySQL AB
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

# Build mysql_fix_privilege_tables.sql
ADD_CUSTOM_COMMAND(OUTPUT ${PROJECT_SOURCE_DIR}/scripts/mysql_fix_privilege_tables.sql
                   COMMAND copy /b
                   mysql_system_tables.sql + mysql_system_tables_fix.sql
                   mysql_fix_privilege_tables.sql
                   DEPENDS
                   ${PROJECT_SOURCE_DIR}/scripts/mysql_system_tables.sql
                   ${PROJECT_SOURCE_DIR}/scripts/mysql_system_tables_fix.sql)

# Build comp_sql - used for embedding SQL in C or C++ programs
ADD_EXECUTABLE(comp_sql comp_sql.c)
TARGET_LINK_LIBRARIES(comp_sql debug dbug mysys strings)

# Use comp_sql to build mysql_fix_privilege_tables_sql.c
GET_TARGET_PROPERTY(COMP_SQL_EXE comp_sql LOCATION)

ADD_CUSTOM_COMMAND(OUTPUT ${PROJECT_SOURCE_DIR}/scripts/mysql_fix_privilege_tables_sql.c
                   COMMAND ${COMP_SQL_EXE}
                   mysql_fix_privilege_tables
                   mysql_fix_privilege_tables.sql
                   mysql_fix_privilege_tables_sql.c
                   DEPENDS comp_sql ${PROJECT_SOURCE_DIR}/scripts/mysql_fix_privilege_tables.sql)

# Add dummy target for the above to be built
ADD_CUSTOM_TARGET(GenFixPrivs
                  ALL
                  DEPENDS ${PROJECT_SOURCE_DIR}/scripts/mysql_fix_privilege_tables_sql.c)

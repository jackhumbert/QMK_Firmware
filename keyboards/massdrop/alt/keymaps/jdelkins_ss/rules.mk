# Copyright 2020 Joel Elkins <joel@elkins.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

ifeq ($(OS),Windows_NT)
	MDLOADER = bin/mdloader_windows
else
	MDLOADER = sudo bin/mdloader_linux
endif

doflash: .build/massdrop_alt_jdelkins_ss.hex
	$(MDLOADER) --first --download $< --restart

USER_NAME := jdelkins

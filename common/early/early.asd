;;; ASGL an abstract argumentation solver in ECL and GECODE.
;;; Copyright (C) 2015  Kilian Sprotte

;;; This program is free software: you can redistribute it and/or modify
;;; it under the terms of the GNU General Public License as published by
;;; the Free Software Foundation, either version 3 of the License, or
;;; (at your option) any later version.

;;; This program is distributed in the hope that it will be useful,
;;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;; GNU General Public License for more details.

;;; You should have received a copy of the GNU General Public License
;;; along with this program.  If not, see <http://www.gnu.org/licenses/>.

(in-package :asdf)

(defsystem :early
    :depends-on (:asgl-config)
    :components
    ((:file "package")
     (:file "graph-input" :depends-on ("package" "cover" "utils"))
     (:file "utils" :depends-on ("package" "cover"))
     (:file "graph" :depends-on ("utils" "cover"))
     (:file "apx" :depends-on ("graph" "cover"))
     (:file "cover" :depends-on ())))

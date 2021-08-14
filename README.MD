# Concept of Fejix
![img](logo/svg/fejix_logo-text-border.svg)

<sub>Don't look inside `src` folder for now. It's just temporary, old and bad.</sub>

# The ViLaSCo model

Widget is defined as a set of four parameters:

* __Visuals__ -- a list of all graphical elements of the widget;
* __Layout__ -- a set of rules that describe how the widget should be placed on a graphical display related to other widgets;
* __Script__ -- program code that is to be executed if the user interacts with the widget (includes changes to the widget visuals and invokation of the program functionality controlled by the widget);
* __Content__ -- a list of _children_ widgets tied to the _parent_ widget in order to be controlled and/or visually grouped;
  * __Static content__ -- a fixed set of widgets needed to display the parent widget. It must be never changed (i.e. no widgets should be added or removed from the list during the run time).
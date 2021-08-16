# Concept of Fejix
![img](images/logo/png/fejix_logo-text-border.png)

<sub>Don't look inside `src` folder for now. It's just temporary, old and bad.</sub>

<sub>P.S. I would be grateful if somebody helped me with the logo - I don't draw very well. Currently it's an orchid.</sub>

# The ViLaSCo model

Widget is defined as a set of four parameters:

* __Visuals__ &mdash; a list of all graphical elements of the widget;
* __Layout__ &mdash; a set of rules that describe how the widget should be placed on a graphical display related to other widgets;
* __Script__ &mdash; program code that is to be executed if the user interacts with the widget (includes changes to the widget visuals and invokation of the program functionality controlled by the widget);
* __Content__ &mdash; a list of _children_ widgets tied to the _parent_ widget in order to be controlled and/or visually grouped;
  * __Static content__ &mdash; a fixed set of widgets needed to display the parent widget. It must be never changed (i.e. no widgets should be added or removed from the static content during the run time).


## Visuals &ndash; Elems

Visuals consist of _elems_ &ndash; the graphical primitives. Every elem has a _shape_ (form) and _fill_ (filling). Here are some examples of elems:

![rect-yellow](images/readme/figures/rect-yellow.svg)
![ellipse-green](images/readme/figures/ellipse-green.svg)
![rrect-texture](images/readme/figures/rrect-texture.svg)

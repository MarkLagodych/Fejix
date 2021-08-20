# Concept of Fejix

__TABLE OF CONTENTS__
- [Concept of Fejix](#concept-of-fejix)
  - [The ViLaSCo model](#the-vilasco-model)
    - [Visuals &ndash; Elems](#visuals--elems)
    - [Layout](#layout)
      - [Area](#area)
  - [Appendix: primitive definitions](#appendix-primitive-definitions)
    - [Rect](#rect)
    - [XRect](#xrect)

----------

## The ViLaSCo model

Widget is defined as a set of four parameters:

* __Visuals__ &mdash; a list of all graphical elements of the widget;
* __Layout__ &mdash; a set of rules that describe how the widget should be placed on a graphical display related to other widgets;
* __Script__ &mdash; program code that is to be executed if the user interacts with the widget (includes changes to the widget visuals and invokation of the program functionality controlled by the widget);
* __Content__ &mdash; a list of _children_ widgets tied to the _parent_ widget in order to be controlled and/or visually grouped;
  * __Static content__ &mdash; a fixed set of widgets needed to display the parent widget. It must be never changed (i.e. no widgets should be added or removed from the static content during the run time).


### Visuals &ndash; Elems

Visuals consist of _elems_ &ndash; the graphical primitives. Every elem has a _shape_ (form) and _fill_ (filling). Here are some examples of elems:

![rect-yellow](images/readme/figures/rect-yellow.svg)
![ellipse-green](images/readme/figures/ellipse-green.svg)
![rrect-gradient](images/readme/figures/rrect-gradient.svg)
![nrect-gradient](images/readme/figures/nrect-gradient.svg)

Each elem has a positioning hint relative to the [area](#area) represented by an [xrect](#xrect).

### Layout

#### Area

## Appendix: primitive definitions

### Rect
A real rectangle with all dimensions specified in pixels
```c
typedef struct {
    int x;
    int y;
    int w;
    int h;
} rect;
```

### XRect
A rectangle with relative units support (percents%)
```c
typedef struct {
    float x;
    float y;
    float w;
    float h;

    // Are dimensions specified in pixels (0) or percents (1) ?
    unsigned x_pc: 1;
    unsigned y_pc: 1;
    unsigned w_pc: 1;
    unsigned h_pc: 1;

    // To what sides the shape is sticky to? (0 - not sticky, 1 - sticky)
    unsigned anchor_top:    1;
    unsigned anchor_right:  1;
    unsigned anchor_bottom: 1;
    unsigned anchor_left:   1;
} xrect;
```

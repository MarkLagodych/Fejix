# Concept of Fejix

__TABLE OF CONTENTS__
- [Concept of Fejix](#concept-of-fejix)
  - [The ViLaSCo model](#the-vilasco-model)
    - [Visuals &ndash; Elems](#visuals--elems)
    - [Layout](#layout)
      - [Area](#area)
  - [Appendix: primitive definitions](#appendix-primitive-definitions)
    - [Units](#units)
    - [Rect](#rect)
    - [XRect](#xrect)

----------

## The ViLaSCo model

Widget is defined as a set of four parameters:

* __Visuals__ &mdash; a list of all graphical elements of the widget;
* __Layout__ &mdash; a set of rules that describe how the widget should be placed on a graphical display related to other widgets;
* __Script__ &mdash; program code that is to be executed if the user interacts with the widget (includes changes to the widget visuals and invokation of the program functionality controlled by the widget);
* __Content__ &mdash; a list of _children_ widgets tied to the _parent_ widget in order to be controlled and/or visually grouped;
  * __Static content__ &mdash; a fixed set of widgets needed to display the parent widget. It must be never changed (i.e. no widgets can be added or removed from the static content during the run time).


### Visuals &ndash; Elems

Visuals consist of _elems_ &ndash; the graphical primitives. Every elem has a _shape_ (form) and _fill_ (filling). Here are some examples of elems:

![rect-yellow](images/readme/figures/rect-yellow.svg)
![ellipse-green](images/readme/figures/ellipse-green.svg)

![rrect-gradient](images/readme/figures/rrect-gradient.svg)
![nrect-gradient](images/readme/figures/nrect-gradient.svg)

Each elem has a positioning hint relative to the [area](#area) represented by an [xrect](#xrect).

### Layout

One of the primary purposes of layout is to compute [area](#area) to make it possible to draw the [visuals](#visuals--elems).

Now, the definition of layout ends. 

#### Area

This is a rectangle of a widget where all visuals are drawn (though some elems like borders can be drawn even outside the area).

## Appendix: primitive definitions

The `int` is assumed to be at least 16 bits.

### Units

Unit      | Short | Considered status
--------- | ----- | -----------------
Pixel     | `px`  | Absolute
Percent   | `%`   | Relative
Font size | `em`  | Relative

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
An eXtended rectangle with relative units support (%, em)

If units are relative, than dimensions are divided by 100 to form a floating-point value

Example:
```c
w = 9915
w_unit = %
```
`w` is computed as `99.15%`

```c
typedef struct {
    int x;
    int y;
    int w;
    int h;

    // px (0), % (1) or em (2)
    unsigned x_unit: 2;
    unsigned y_unit: 2;
    unsigned w_unit: 2;
    unsigned h_unit: 2;

    unsigned anchor_x: 1; // 0 is left, 1 is right
    unsigned anchor_y: 1; // 0 is top, 1 is bottom
    unsigned _unused_: 6; 
} xrect;
```

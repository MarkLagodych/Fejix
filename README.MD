# Concept of Fejix
Here are theoretical fundamentals of what is Fejix. 

[Go to implementation README](IMPL_README.MD) 

__TABLE OF CONTENTS__
- [Concept of Fejix](#concept-of-fejix)
    - [The ViLaSCo model](#the-vilasco-model)
        - [Visuals &ndash; Elems](#visuals--elems)
        - [Layout](#layout)
            - [Strategies](#strategies)
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

#### Strategies

There are several strategies 

__Relative layout__: [xrect](#xrect) relative to the parent.

__Flow layout__: not yet implemented, but it must work similarly to HTML element flow or Tkinter's `pack` method.


#### Area

This is a rectangle of a widget where all visuals are drawn (though some elems like borders can be drawn outside the area).

## Appendix: primitive definitions

The `int` is assumed to be at least 16 bits.

### Units

Unit       | Sign  | Considered status | Relative to
---------- | ----- | ----------------- | -------------
Pixel      | `px`  | Absolute          | Screen pixels
Percent    | `%`   | Relative          | 1% of parent's width/height
Em         | `em`  | Relative          | Parent font size

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
w = 9915 // Raw value
uw = %   // Units
// Computed: 99.15%
```

```c
typedef struct {
    int x;
    int y;
    int w;
    int h;

    // Units: px (0), % (1) or em (2)
    unsigned ux: 2;
    unsigned uy: 2;
    unsigned uw: 2;
    unsigned uh: 2;

    // Anchors
    unsigned ax: 1; // 0 is x, 1 is area.w - x
    unsigned ay: 1; // 0 is y, 1 is area.h - h
    unsigned aw: 1; // 0 is w, 1 is area.w - w
    unsigned ah: 1; // 0 is h, 1 is area.h - h

    unsigned _unused: 4; 
} xrect;
```

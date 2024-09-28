# BrocDX

I would like to take my experience writing past renderers and restart a new one with the learnings. I would also like to apply my new visions of programming in this one with simplicity in mind. Trying my best to follow a C-style C++ model.

Here's a short list of goals to keep in mind while implementing this renderer

- C-Style C++ as mentioned
    * no classes
    * no RAII
    * try to allocate through arenas as much as possible
- Try to keep the renderer interface in one header file
- Can split implementations to multiple .cpp files
    * compile down to one .lib

I also want to be able to work on more advanced rendering techniques when the renderer will take form. So, with this in mind, while working need to make it possible to implement these features later on.

- deferred rendering
- shadow maps
- FXAA
- multithreading command list recording
- motion vectors
- jittering
- async compute
- gpu driven rendering (DrawIndirect)
    * occlution culling

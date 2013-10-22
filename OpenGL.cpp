

    GLenum enablesMax = 0;
    GLenum enables[] = {GL_ALPHA_TEST, GL_AUTO_NORMAL, GL_BLEND, GL_COLOR_LOGIC_OP,
                        GL_COLOR_MATERIAL, GL_CULL_FACE, GL_DEPTH_TEST, GL_DITHER,
                        GL_FOG, GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4,
                        GL_LIGHTING, GL_LINE_SMOOTH, GL_LINE_STIPPLE, GL_LOGIC_OP,
                        /*GL_MAP1_0, GL_MAP1_1, GL_MAP2_0, GL_MAP2_1, */GL_NORMALIZE,
                        GL_POINT_SMOOTH, GL_POLYGON_OFFSET_EXT, GL_POLYGON_OFFSET_FILL,
                        GL_POLYGON_OFFSET_LINE, GL_POLYGON_OFFSET_POINT, GL_POLYGON_SMOOTH,
                        GL_POLYGON_STIPPLE, GL_SCISSOR_TEST, GL_STENCIL_TEST, GL_TEXTURE_1D,
                        GL_TEXTURE_2D, GL_TEXTURE_3D_EXT, GL_TEXTURE_GEN_S, GL_TEXTURE_GEN_T,
                        GL_TEXTURE_GEN_R, GL_TEXTURE_GEN_Q, 0};
    std::vector<bool> enableValues;
    for (int i = 0; enables[i] != enablesMax; ++i)
      {
      enableValues.push_back(glIsEnabled(enables[i]));
      }
    ... // renderWindow->Render();
    for (int i = 0; enables[i] != enablesMax; ++i)
      {
      if (enableValues[i] != glIsEnabled(enables[i]))
        {
        qDebug() << "glEnable has changed " << i << "=" << glIsEnabled(enables[i]);
        }
      }

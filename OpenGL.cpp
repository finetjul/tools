/** Test what state has changed
*/
glPushAttrib(
    GL_ENABLE_BIT
    | GL_COLOR_BUFFER_BIT
    | GL_STENCIL_BUFFER_BIT
    | GL_DEPTH_BUFFER_BIT
    | GL_POLYGON_BIT
    | GL_PIXEL_MODE_BIT
    | GL_TEXTURE_BIT
);
// renderWindow->Render();
glPopAttrib();

/** Test what glEnable variable some rendering code has changed
*/
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
// renderWindow->Render();
for (int i = 0; enables[i] != enablesMax; ++i)
  {
  if (enableValues[i] != glIsEnabled(enables[i]))
    {
    qDebug() << "glEnable has changed " << i << "=" << glIsEnabled(enables[i]);
    }
  }
  
  
  
/** Paint a black box in OpenGL
*/
void QVTKQuickItemPrivate::paintBlackBox()
{
  Q_Q(QVTKQuickItem);
  qDebug() << "start blackbox";
  static const GLfloat lightPos[4] = { 5.0f, 5.0f, 10.0f, 1.0f };

  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  //glEnable(GL_DEPTH_TEST);
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glDisable(GL_SCISSOR_TEST);
  glDisable(GL_STENCIL_TEST);
  glDisable(GL_ALPHA_TEST);

  //int side = qMin(window()->width(), window()->height());
  //glViewport((window()->width() - side) / 2, (window()->height() - side) / 2, side, side);
  //glViewport(this-x(), this->y(), this->width(), this->height());
  QPointF originInWindow= q->mapToScene(QPointF(0,0));
  qDebug() << "origin: " << originInWindow.x() << originInWindow.y();
  qDebug() << "gemo: " << originInWindow.x() << q->window()->height() - q->height() - originInWindow.y() <<
              static_cast<GLsizei>(q->width())<< static_cast<GLsizei>(q->height());
  glViewport(originInWindow.x(), q->window()->height() - q->height() - originInWindow.y(),
             static_cast<GLsizei>(q->width()), static_cast<GLsizei>(q->height()));
//  glViewport(0, 0,
//             static_cast<GLsizei>(this->window()->width()), static_cast<GLsizei>(this->window()->height()));


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, +1.0, -1.0, 1.0, 5.0, 60.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0.0, 0.0, -40.0);



//glEnable(GL_BLEND);
//glBlendFunc(GL_SRC_ALPHA, GL_ONE);

//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
//glOrtho(0,window()->width(), window()->height(), 0,0,1);

//glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();
//glTranslated(0.0, 0.0, 10.0);

  glClearColor(1., 0., 0., 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 1, 0, 1);

  glColor3f(0.f,0.f,1.f);
  glBegin(GL_QUADS);
  glVertex3f(-1.f,-1.f,10.f);
  glVertex3f(-1.f,1.f,10.f);
  glVertex3f(1.f,1.f,10.f);
  glVertex3f(1.f,-1.f,10.f);
  glEnd();
  qDebug() << "end blackbox";
}


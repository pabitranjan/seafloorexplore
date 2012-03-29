//
//  SLSOpenGLES20Renderer.h
//  Molecules
//
//  The source code for Molecules is available under a BSD license.  See License.txt for details.
//
//  Created by Brad Larson on 4/12/2011.
//

#import "SLSOpenGLESRenderer.h"

#define ENABLETEXTUREDISPLAYDEBUGGING 1

@class GLProgram;
@class Scene;
@class Simulation;
@interface MyOpenGLES20Renderer : SLSOpenGLESRenderer 
{
   
   
    CGSize currentViewportSize;
    Scene *scene;
    Simulation *sim ;
	NSString *defaultModelName;
    int drawn;
}
@property(assign,nonatomic)     Simulation *sim ;


// OpenGL drawing support
- (BOOL)createFramebuffer:(GLuint *)framebufferPointer size:(CGSize)bufferSize renderBuffer:(GLuint *)renderbufferPointer depthBuffer:(GLuint *)depthbufferPointer texture:(GLuint *)backingTexturePointer layer:(CAEAGLLayer *)layer;
- (void)switchToDisplayFramebuffer;
- (void)shutdownVT;
-(void)startupVT:(NSString *)name;
- (void)showStatusIndicator;
- (void)hideStatusIndicator;


@end


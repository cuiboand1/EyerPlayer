#include "YUVRenderTask.hpp"

#include "EyerGLShader/Shader.hpp"

namespace EyerPlayer {
    YUVRenderTask::YUVRenderTask()
    {

    }

    YUVRenderTask::~YUVRenderTask()
    {

    }

    int YUVRenderTask::Render()
    {
        yuv2texture->Draw();
        return 0;
    }

    int YUVRenderTask::Init()
    {
        float vertex[] = {
                1.0, 1.0, 0.0,
                1.0, -1.0, 0.0,
                -1.0, -1.0, 0.0,
                -1.0, 1.0, 0.0
        };
        float coor[] = {
                1.0, 1.0, 0.0,
                1.0, 0.0, 0.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0
        };
        unsigned int vertexIndex[] = {
                0, 1, 2,
                0, 2, 3
        };

        yuv2texture = new Eyer::EyerGLDraw(Eyer::EYER_GL_SHADER::YUV_2_TEXTURE_VERTEX_SHADER, Eyer::EYER_GL_SHADER::YUV_2_TEXTURE_FRAGMENT_SHADER);
        yuv2texture->Init();

        vao = new Eyer::EyerGLVAO();

        vao->AddVBO(vertex, sizeof(vertex), 0);
        vao->AddVBO(coor, sizeof(coor), 1);
        vao->SetEBO(vertexIndex, sizeof(vertexIndex));

        yuv2texture->SetVAO(vao);

        y = new Eyer::EyerGLTexture();
        u = new Eyer::EyerGLTexture();
        v = new Eyer::EyerGLTexture();

        int w = videoFrame->GetWidth();
        int h = videoFrame->GetHeight();
        int yLen = w * h;
        int uLen = w * h / 4;
        int vLen = w * h / 4;

        unsigned char * yData = (unsigned char *)malloc(yLen);
        unsigned char * uData = (unsigned char *)malloc(uLen);
        unsigned char * vData = (unsigned char *)malloc(vLen);

        videoFrame->GetYData(yData);
        videoFrame->GetUData(uData);
        videoFrame->GetVData(vData);

        y->SetDataRedChannel(yData, w, h);
        u->SetDataRedChannel(uData, w / 2, h / 2);
        v->SetDataRedChannel(vData, w / 2, h / 2);

        yuv2texture->PutTexture("y", y, 0);
        yuv2texture->PutTexture("u", u, 1);
        yuv2texture->PutTexture("v", v, 2);

        yuv2texture->PutUniform1i("colorRange", 1);
        yuv2texture->PutUniform1i("reverseY", 1);

        free(yData);
        free(uData);
        free(vData);

        return 0;
    }

    int YUVRenderTask::Destory()
    {
        // EyerLog("YUVRenderTask Destory\n");
        if(yuv2texture != nullptr){
            delete yuv2texture;
            yuv2texture = nullptr;
        }
        if(vao != nullptr){
            delete vao;
            vao = nullptr;
        }
        if(y != nullptr){
            delete y;
            y = nullptr;
        }
        if(u != nullptr){
            delete u;
            u = nullptr;
        }
        if(v != nullptr){
            delete v;
            v = nullptr;
        }
        if(videoFrame != nullptr){
            delete videoFrame;
            videoFrame = nullptr;
        }
        return 0;
    }

    int YUVRenderTask::SetFrame(Eyer::EyerAVFrame * _videoFrame)
    {
        videoFrame = _videoFrame;
        return 0;
    }
}
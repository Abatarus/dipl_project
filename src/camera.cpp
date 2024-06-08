#include "headers/camera.h"

Camera::Camera(glm::vec3 position,
               glm::vec3 up,
               float yaw, float pitch) : front(glm::vec3(0.0f, 0.0f, -1.0f)),
                                         fov(FOV), zNear(ZNEAR), zFar(ZFAR), aspectRatio(ASPECTRATIO),
                                         movementSpeed(SPEED), sensitivity(SENSITIVITY)
{
    this->position = position;
    this->worldUp = up;
    this->yaw = yaw;
    this->pitch = pitch;
    UpdateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ,
               float upX, float upY, float upZ,
               float yaw, float pitch) : front(glm::vec3(0.0f, 0.0f, -1.0f)),
                                         fov(FOV), zNear(ZNEAR), zFar(ZFAR), aspectRatio(ASPECTRATIO),
                                         movementSpeed(SPEED), sensitivity(SENSITIVITY)
{
    position = glm::vec3(posX, posY, posZ);
    worldUp = glm::vec3(upX, upY, upZ);
    yaw = yaw;
    pitch = pitch;
    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return glm::perspective(glm::radians(fov), aspectRatio, zNear, zFar);
}

void Camera::Move(int32_t dirs, float deltaTime)
{
    float velocity = movementSpeed * deltaTime;
    glm::vec3 direction = glm::vec3(0.f, 0.f, 0.f);
    direction.z = (dirs & CAM_FORWARD) / CAM_FORWARD - (dirs & CAM_BACKWARD) / CAM_BACKWARD;
    direction.x = (dirs & CAM_RIGHT) / CAM_RIGHT - (dirs & CAM_LEFT) / CAM_LEFT;
    direction.y = (dirs & CAM_UP) / CAM_UP - (dirs & CAM_DOWN) / CAM_DOWN;

    // sadnessforever, thx for bugfix
    if (direction != glm::vec3(0, 0, 0))
    {
        direction = glm::normalize(direction);
    }

    position += front * velocity * direction.z;
    position += right * velocity * direction.x;
    position += up * velocity * direction.y;
    UpdateCameraVectors();
}

void Camera::Rotate(float xOffset, float yOffset, GLboolean constrainPitch)
{
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (constrainPitch)
    {
        if (pitch > 89.0f)
        {
            pitch = 89.0f;
        }
        if (pitch < -89.0f)
        {
            pitch = -89.0f;
        }
    }

    UpdateCameraVectors();
}

void Camera::ChangeFOV(double value)
{
    fov -= (float)value;
    if (fov < 1.0f) {
        fov = 1.0f;
    }
    if (fov > 120.0f) {
        fov = 120.0f;
    }
    UpdateCameraVectors();
}

void Camera::UpdateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}
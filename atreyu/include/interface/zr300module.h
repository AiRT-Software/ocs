#pragma pack(push, 1)
    // ACTIONS
    // Non payload actions are built using a single AiRT command packet:
    // { 'A', RCAM_MODULE, <ACTION>}
    // where <ACTION> can be any of the \sa StdMessage::RCamCommandType that do not require a parameter


    // NOTIFICATIONS

    // Two-part message
    // First part
    struct pointCloudHeader
    {
        const AIRT_Message_Header header{StdMessage::POINTCLOUD_MODULE, StdMessage::PCL_SINGLE};
        uint32_t numPoints;
        int32_t i, j, k;
    };
    // Second part
    struct point {
        float x, y, z;
        uint8_t r, g, b, a;
        //uint32_t color; // MSBe [0] [blue] [green] [red] LSB
    };
    // other Second part
    struct pointNormal {
        float x, y, z;
        uint8_t r, g, b, a;
        float normal_x, normal_y, normal_z;

        pointNormal(float x_ = 0.0, float y_ = 0.0, float z_ = 0.0, uint8_t r_ = 0, uint8_t g_ = 0, uint8_t b_ = 0, uint8_t a_ = 0,
                    float normal_x_ = 0.0, float normal_y_ = 0.0, float normal_z_ = 0.0)
            :
              x(x_), y(y_), z(z_), r(r_), g(g_), b(b_), a(a_),
              normal_x(normal_x_), normal_y(normal_y_), normal_z(normal_z_)
        {};

        pointNormal(const pointNormal & other)
        {
            x = other.x; y = other.y; z = other.z;
            r = other.r; g = other.g; b = other.b; a = other.a;
            normal_x = other.normal_x; normal_y = other.normal_y; normal_z = other.normal_z;
        };
    };

    struct accelerometerFrameData
    {
        double timestamp;
        float x, y, z;   //m/s^2
    };
#pragma pack(pop)

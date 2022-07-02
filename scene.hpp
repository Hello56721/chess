#ifndef E908B7A4_6FBD_42F8_8161_D6810EE55C2E
#define E908B7A4_6FBD_42F8_8161_D6810EE55C2E

namespace chess
{
    // An interface class that all scenes will inherit
    class scene_t
    {
    public:
        scene_t() = default;
        
        virtual void update() {};
        
        virtual void render() {};
        
        virtual ~scene_t() {}
    };
}

#endif /* E908B7A4_6FBD_42F8_8161_D6810EE55C2E */

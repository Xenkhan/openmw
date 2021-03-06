#ifndef CSM_TOOLS_SOUNDGENCHECK_HPP
#define CSM_TOOLS_SOUNDGENCHECK_HPP

#include "../world/data.hpp"

#include "../doc/stage.hpp"

namespace CSMTools
{
    /// \brief VerifyStage: make sure that sound gen records are internally consistent
    class SoundGenCheckStage : public CSMDoc::Stage
    {
            const CSMWorld::IdCollection<ESM::SoundGenerator> &mSoundGens;
            const CSMWorld::IdCollection<ESM::Sound> &mSounds;
            const CSMWorld::RefIdCollection &mReferenceables;
            bool mIgnoreBaseRecords;

        public:
            SoundGenCheckStage(const CSMWorld::IdCollection<ESM::SoundGenerator> &soundGens,
                               const CSMWorld::IdCollection<ESM::Sound> &sounds,
                               const CSMWorld::RefIdCollection &referenceables);

            virtual int setup();
            ///< \return number of steps

            virtual void perform(int stage, CSMDoc::Messages &messages);
            ///< Messages resulting from this stage will be appended to \a messages.
    };
}

#endif

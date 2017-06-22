/*
 * Copyright 2017 Damien Giron <contact@damiengiron.me>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifndef SWARM_MAPPING_ENCODER_HXX
#include "Encoder.hxx"
#endif


namespace swarm {
    namespace mapping {
        
        template <class Provider>
        template <typename T>
        void Encoder<Provider>::encode(const std::string & name, const T &value) {
            provider_.encode(name, value);
        }
        
        template <class Provider>
        template <typename T>
        void Encoder<Provider>::encode(const std::string & name, const T *value) {
            if (value == nullptr) {
                // FIXME Log
            } else {
                encode(name, *value);
            }
        }
        
        template <class Provider>
        template <typename T>
        void Encoder<Provider>::encode(const std::string & name, const std::shared_ptr<T> value) {
            if (value) {
                encode(name, *value);
            } else {
                // FIXME Log
            }
        }
                    
        template <class Provider>
        template <class D, typename V>
        void Encoder<Provider>::encode(Mapping<Provider, D, V> & mapper, const std::string name, const V & value) {
            auto encoderProvider = provider_.subObject(name);
            Encoder<Provider> encoder{*encoderProvider};
            mapper.encode(encoder, value);
        }
    }
}
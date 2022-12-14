/********************************************************************************************************
 * @file NodeIdentitySetMessage.java
 *
 * @brief for TLSR chips
 *
 * @author telink
 * @date Sep. 30, 2010
 *
 * @par Copyright (c) 2010, Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *
 *			 The information contained herein is confidential and proprietary property of Telink 
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms 
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai) 
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in. 
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this 
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided. 
 *
 *******************************************************************************************************/
package com.telink.ble.mesh.core.message.config;

import com.telink.ble.mesh.core.MeshUtils;
import com.telink.ble.mesh.core.message.Opcode;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * The Config Node Identity Set is an acknowledged message used to set the current Node Identity state for a subnet
 * <p>
 * The response to a Config Node Identity Set message is a Config Node Identity Status message.
 * {@link NodeIdentityStatusMessage}
 */

public class NodeIdentitySetMessage extends ConfigMessage {

    public int netKeyIndex;

    public byte identity;


    public static NodeIdentitySetMessage getSimple(int destinationAddress, int netKeyIndex, byte identity) {
        NodeIdentitySetMessage message = new NodeIdentitySetMessage(destinationAddress);
        message.netKeyIndex = netKeyIndex;
        message.identity = identity;
        return message;
    }

    public NodeIdentitySetMessage(int destinationAddress) {
        super(destinationAddress);
    }

    @Override
    public int getOpcode() {
        return Opcode.NODE_ID_SET.value;
    }

    @Override
    public int getResponseOpcode() {
        return Opcode.NODE_ID_STATUS.value;
    }

    @Override
    public byte[] getParams() {

        // netKey index lower 12 bits
        int netAppKeyIndex = (netKeyIndex & 0x0FFF);
        ByteBuffer paramsBuffer = ByteBuffer.allocate(3).order(ByteOrder.LITTLE_ENDIAN)
                .putShort((short) (netKeyIndex & 0x0FFF))
                .put((byte) identity);
        return paramsBuffer.array();
    }

    public void setNetKeyIndex(int netKeyIndex) {
        this.netKeyIndex = netKeyIndex;
    }

    public void setIdentity(byte identity) {
        this.identity = identity;
    }
}

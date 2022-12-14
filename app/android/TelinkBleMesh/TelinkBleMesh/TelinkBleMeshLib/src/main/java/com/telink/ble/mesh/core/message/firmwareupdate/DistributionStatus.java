/********************************************************************************************************
 * @file     DistributionStatus.java 
 *
 * @brief    for TLSR chips
 *
 * @author	 telink
 * @date     Sep. 30, 2010
 *
 * @par      Copyright (c) 2010, Telink Semiconductor (Shanghai) Co., Ltd.
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
package com.telink.ble.mesh.core.message.firmwareupdate;

public enum DistributionStatus {


    SUCCESS(0x00, "The message was processed successfully"),

    INSUFFICIENT_RESOURCES(0x01, "Insufficient resources on the node"),

    WRONG_PHASE(0x02, "The operation cannot be performed while the server is in the current phase"),

    INTERNAL_ERROR(0x03, "An internal error occurred on the node"),


    FIRMWARE_NOT_FOUND(0x04, "The requested firmware image is not stored on the Distributor"),

    INVALID_APPKEY_INDEX(0x05, "The AppKey identified by the AppKey Index is not known to the node"),

    RECEIVERS_LIST_EMPTY(0x06, "There are no Updating nodes in the Distribution Receivers List state"),

    BUSY_WITH_DISTRIBUTION(0x07, "Another firmware image distribution is in progress"),

    BUSY_WITH_UPLOAD(0x08, "Another upload is in progress"),

    URI_NOT_SUPPORTED(0x09, "The URI scheme name indicated by the Update URI is not supported"),

    URI_MALFORMED(0x0A, "The format of the Update URI is invalid"),

    UNKNOWN_ERROR(0xFF, "unknown error");

    public final int code;
    public final String desc;

    DistributionStatus(int code, String desc) {
        this.code = code;
        this.desc = desc;
    }

    public static DistributionStatus valueOf(int code) {
        for (DistributionStatus status : values()) {
            if (status.code == code) return status;
        }
        return UNKNOWN_ERROR;
    }
}

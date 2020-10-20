set(COMPONENT_SRCS "main.c"
                   "iot.c"
                   "motor.c"
                   "weight.c"
                   "pir.c")
set(COMPONENT_ADD_INCLUDEDIRS ".")

register_component()

target_add_binary_data(${COMPONENT_TARGET} "certs/private_key.pem" TEXT)

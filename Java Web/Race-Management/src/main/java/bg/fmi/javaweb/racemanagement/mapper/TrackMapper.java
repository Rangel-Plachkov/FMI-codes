package bg.fmi.javaweb.racemanagement.mapper;

import bg.fmi.javaweb.racemanagement.models.Track;
import bg.fmi.javaweb.racemanagement.dtos.TrackDTO;

import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

@Mapper(componentModel = "spring")
public interface TrackMapper {
    @Mapping(source = "name", target = "name")
    @Mapping(source = "length", target = "length")
    Track dtoToEntity(TrackDTO trackDTO);

    @Mapping(source = "name", target = "name")
    @Mapping(source = "length", target = "length")
    TrackDTO entityToDto(Track track);

}
